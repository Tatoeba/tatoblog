/**
 * Tatoblog  A blog platform in C++
 *
 * Copyright (C) 2013 Allan Simon <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Tatoblog
 * @author   Allan Simon <allan.simon@supinfo.com>
 * @package  Controllers
 * @link     https://github.com/allan-simon/tatoblog@
 *
 */

#ifndef TATOBLOGCONTROLLERS_WEBS_%%CONTROLLER_INCLUDE%%_H
#define TATOBLOGCONTROLLERS_WEBS_%%CONTROLLER_INCLUDE%%_H

#include <cppcms_skel/controllers/webs/Controller.h>


//needed to avoid to include models directly here,
//which would have the side effects to require to recompile the
// controller every time we modify a model. even though it does
// not affect the controller
namespace tatoblog {

namespace models {
    // %%%NEXT_CLASS_MODEL_CTRL_MARKER%%%
}

namespace controllers {
namespace webs {
/**
 * @class %%CONTROLLER_NAME%% %%CONTROLLER_DESCRIPTION%%
 * @since %%CONTROLLER_TODAY%%
 */
class %%CONTROLLER_NAME%% : public ::controllers::webs::Controller {
    public:
        /**
         * @brief Constructor
         * @since %%CONTROLLER_TODAY%%
         */
        %%CONTROLLER_NAME%%(cppcms::service &serv);

        /**
         * @brief Destructor
         * @since %%CONTROLLER_TODAY%%
         */
        ~%%CONTROLLER_NAME%%();

    private:
        // %%%NEXT_VAR_MODEL_CTRL_MARKER%%%

// %%%NEXT_ACTION_MARKER%%% , do not delete

};

} // End namespace webs
} // End namespace controllers
} // End namespace tatoblog

#endif
