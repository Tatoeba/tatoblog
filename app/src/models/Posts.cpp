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
 * @package  Models
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/allan-simon/tatoblog@
 */


#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <limits>
#include <cppdb/frontend.h>

#include "models/Posts.h"


namespace tatoblog {
namespace models {

/**
 *
 */
Posts::Posts() :
    SqliteModel()
{
}

/**
 *
 */
int Posts::create(
    const results::Post &post,
    const int userId
) {
    cppdb::statement statement = sqliteDb.prepare(
        "INSERT INTO posts("
        "    title,"
        "    slug,"
        "    introduction,"
        "    main,"
        "    lang,"
        "    user_id"
        ") "
        "VALUES ( "
        "   ? ,"
        "   ? ,"
        "   ? ,"
        "   ? ,"
        "   ? ,"
        "   ? "
        ")"
    );
    
    statement.bind(post.title);
    statement.bind(post.slug);
    statement.bind(post.introduction);
    statement.bind(post.main);
    statement.bind(post.lang);
    statement.bind(userId);

    if (!execute_simple(statement)) {
        return POST_CREATION_ERROR;
    }
    const int id = statement.last_insert_id();
    return id;
}

/**
 *
 */
results::Post Posts::get_from_lang_and_slug(
    const std::string &lang,
    const std::string &slug
) {
    cppdb::statement getFromLangAndSlug = sqliteDb.prepare(
        "SELECT id as post_id, * FROM posts "
        "WHERE lang = ? AND slug = ? LIMIT 1"
    );
    getFromLangAndSlug.bind(lang);
    getFromLangAndSlug.bind(slug);

    cppdb::result res = getFromLangAndSlug.row();
    results::Post post = get_from_result(res);
    
    getFromLangAndSlug.reset();
    return post;
}

/**
 *
 */
results::Posts Posts::get_all(void) {
    results::Post post;
    cppdb::statement allPosts = sqliteDb.prepare(
        "SELECT "
        "   id,   "
        "   lang, "
        "   slug, "
        "   title, "
        "   introduction "
        "FROM posts "
        "ORDER BY id DESC"
    );

    cppdb::result res = allPosts .query();
    results::Posts posts;
    while (res.next()) {
        results::Post tmpPost(
            res.get<int>("id"),
            res.get<std::string>("lang"),
            res.get<std::string>("slug"),
            res.get<std::string>("title"),
            res.get<std::string>("introduction")
        );
        posts.push_back(tmpPost);
    }
    allPosts.reset();
    return posts;
}

/**
 *
 */
results::Post Posts::get_from_result(
    cppdb::result &res
) {
    results::Post post;
    
    if (!res.empty()) {
        post.id = res.get<int>("post_id");
        post.lang = res.get<std::string>("lang");
        post.introduction = res.get<std::string>("introduction");
        post.main = res.get<std::string>("main");
        post.slug = res.get<std::string>("slug");
        post.title = res.get<std::string>("title");
    } else {
        post.id = 0;
    }
    return post;
}

/**
 *
 */
int Posts::edit(
    const results::Post &post
) {
    cppdb::statement statement = sqliteDb.prepare(
        "UPDATE posts "
        "SET"
        "    title = ?,"
        "    slug = ?,"
        "    introduction = ?,"
        "    main = ?,"
        "    lang = ?"
        "WHERE "
        "    id = ? "
    );

    // update part
    statement.bind(post.title);
    statement.bind(post.slug);
    statement.bind(post.introduction);
    statement.bind(post.main);
    statement.bind(post.lang);

    // where part
    statement.bind(post.id);

    if (!execute_simple(statement)) {
        return POST_EDITION_ERROR;
    }
    return 1;
}





} // end namespace models
} // end namespace tatoblog


