/**
 * Tatoblog  A blog platform in C++
 * Copyright (C) 2013 Allan Simon <allan.simon@supinfo.com> 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @category Tatoblog
 * @package  Models
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/allan-simon/tatoblog@
 */

#ifndef TATOBLOG_%%MODEL_INCLUDE%%
#define TATOBLOG_%%MODEL_INCLUDE%%



#include "cppcms_skel/models/SqliteModel.h"
namespace models {


/**
 * @class %%MODEL_NAME%%
 * 
 * @brief %%MODEL_DESCRIPTION%%
 * @since %%MODEL_TODAY%%       
 *
 */
class %%MODEL_NAME%% : public SqliteModel {
    public:
        /**
         * @brief Constructor
         * @since %%MODEL_TODAY%%
         */
        %%MODEL_NAME%%();

};

} // end namespace models 

#endif
