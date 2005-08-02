/*----------------------------------------------------------------------*\
|* spkg - The Unofficial Slackware Linux Package Manager                *|
|*                                      designed by Ond�ej Jirman, 2005 *|
|*----------------------------------------------------------------------*|
|*          No copy/usage restrictions are imposed on anybody.          *|
\*----------------------------------------------------------------------*/

#include "cmd-private.h"

/* public 
 ************************************************************************/

gint cmd_sync(const struct cmd_options* opts, struct error* e)
{
  g_assert(opts != 0);
  g_assert(e != 0);

  msg_setup("sync", opts->verbosity);

  if (opts->mode == CMD_MODE_FROMLEGACY)
  {
    _inform("synchronizing legacydb -> spkgdb");
    if (!opts->dryrun)
      db_sync_from_legacydb();
  }
  else if (opts->mode == CMD_MODE_TOLEGACY)
  {
    _inform("synchronizing spkgdb -> legacydb");
    if (!opts->dryrun)
      db_sync_to_legacydb();
  }
  else
  {
    e_set(E_FATAL,"invalid mode");
    return 1;
  }
  if (!e_ok(e))
  {
    e_set(E_FATAL,"sync failed");
    return 1;
  }
  return 0;
}
