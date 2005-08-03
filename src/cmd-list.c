/*----------------------------------------------------------------------*\
|* spkg - The Unofficial Slackware Linux Package Manager                *|
|*                                      designed by Ond�ej Jirman, 2005 *|
|*----------------------------------------------------------------------*|
|*          No copy/usage restrictions are imposed on anybody.          *|
\*----------------------------------------------------------------------*/
#include <stdio.h>
#include <fnmatch.h>

#include "cmd-private.h"

/* private
 ************************************************************************/

typedef GSList* (*query_func)(db_selector, const void*, db_query_type);

static gint _glob_selector(const struct db_pkg* p, const void* d)
{
  gint s = fnmatch(d, p->name, 0);
  if (s == FNM_NOMATCH)
    return 0;
  if (s == 0)
    return 1;
  return -1;
}

/* public 
 ************************************************************************/

gint cmd_list(
  const gchar* regexp,
  cmd_list_mode mode,
  gboolean legacydb,
  const struct cmd_options* opts,
  struct error* e
)
{
  g_assert(opts != 0);
  g_assert(e != 0);

  GSList* list;
  GSList* i;

  query_func query = legacydb?db_legacy_query:db_query;

  switch (mode)
  {
    case CMD_MODE_GLOB:
      list = query(_glob_selector, regexp, DB_QUERY_NAMES);
      if (!e_ok(e))
      {
        e_set(E_ERROR, "query failed");
        goto err;
      }
      for (i=list; i!=0; i=i->next)
        printf("%s\n", (gchar*)i->data);
      db_free_query(list, DB_QUERY_NAMES);
    break;
    case CMD_MODE_ALL:
      list = query(0, 0, DB_QUERY_NAMES);
      if (!e_ok(e))
      {
        e_set(E_ERROR, "query failed");
        goto err;
      }
      for (i=list; i!=0; i=i->next)
        printf("%s\n", (gchar*)i->data);
      db_free_query(list, DB_QUERY_NAMES);
    break;
    default:
      e_set(E_FATAL, "invalid mode");
      goto err;
  }

  return 0;
 err:
  return 1;
}
