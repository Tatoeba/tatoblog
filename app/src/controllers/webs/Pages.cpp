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
 *
 * @category Tatoblog
 * @package  Controllers
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/allan-simon/tatoblog@
 */

#include <cppcms/session_interface.h>
#include <cppcms_skel/contents/forms/change_interface_langs.h>
#include "Pages.h"

#include "contents/Pages.h"

#include "models/Posts.h"

#include "generics/markdown.h"


namespace tatoblog {
namespace controllers {
namespace webs {

Pages::Pages(cppcms::service& serv) : Controller(serv) {
    dispatcher().assign("", &Pages::homepage, this);
}

/**
 *
 */
void Pages::change_interface_lang_treat() {
    forms::InterfaceLang form;
    form.set_langs();
    form.load(context());
    if(!form.validate()) {
        go_back_to_previous_page();
    }

    session()["interfaceLang"] =  form.interfaceLang.selected_id();

    go_back_to_previous_page();



}

/**
 *
 */
void Pages::homepage() {
    contents::pages::Homepage c;
    init_content(c);

    models::Posts postsModel;     
    
    c.markdown = mymarkdown;
    c.posts = postsModel.get_all();

    render("homepage", c);
}


} // End namespace webs
} // End namespace controllers
} // end of namespace tatoblog
