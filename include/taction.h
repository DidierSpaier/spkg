/*----------------------------------------------------------------------*\
|* spkg - The Unofficial Slackware Linux Package Manager                *|
|*                                      designed by Ond�ej Jirman, 2005 *|
|*----------------------------------------------------------------------*|
|*          No copy/usage restrictions are imposed on anybody.          *|
\*----------------------------------------------------------------------*/
/** @addtogroup other_api */
/*! @{ */

#ifndef __TRANSACTION_H
#define __TRANSACTION_H

#include <glib.h>
#include "error.h"

#define TA_ACTIVE  E(0) /**< another transaction is still active */
#define TA_NACTIVE E(1) /**< transaction is not active */

/** Initialize current transaction.
 * 
 * @param root root directory
 * @param e error object
 * @return 0 on success, 1 on error
 */
extern gint ta_initialize(const gchar* root, struct error* e);

/** Finalize current transaction.
 * 
 * @return 0 on success, 1 on error
 */
extern gint ta_finalize();

/** Rollback current transaction.
 * 
 * @return 0 on success, 1 on error
 */
extern gint ta_rollback();

/** Add action to the current transaction.
 * 
 * @param path path to the transactioned object
 * @param is_dir if path points to a directory
 * @return 0 on success, 1 on error
 */
extern gint ta_keep_remove(gchar* path, gboolean is_dir);

/** Add action to the current transaction.
 * 
 * @param path path to the transactioned object
 * @param fin_path destination path
 * @return 0 on success, 1 on error
 */
extern gint ta_move_remove(gchar* path, gchar* fin_path);

#endif

/*! @} */

