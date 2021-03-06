/*
 * Copyright (C) 2006-2013 Christopho, Solarus - http://www.solarus-games.org
 * 
 * Solarus is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Solarus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SOLARUS_TREASURE_H
#define SOLARUS_TREASURE_H

#include "Common.h"
#include <string>

/**
 * \brief Represents an item that the hero brandishes when he receives it.
 *
 * Treasures include all items the hero can get in chest, buy in a shop,
 * pick on the ground or get from scripts (e.g. when talking to an NPC).
 *
 * A treasure is represented as the following values:
 * - the item name: a string identifying the nature of the treasure,
 * - the variant: an integer indicating the variant of this item (some items
 * may have several variants),
 * - a savegame variable: name of the saved boolean variable that indicates
 * whether the player has found this treasure (or an empty string if the treasure
 * is not saved).
 */
class Treasure {

  public:

    Treasure(Game& game, const std::string& item_name, int variant,
        const std::string& savegame_variable);
    Treasure(const Treasure& other);
    ~Treasure();
    Treasure& operator=(const Treasure& other);

    Game& get_game() const;
    EquipmentItem& get_item() const;
    const std::string& get_item_name() const;
    int get_variant() const;
    const std::string& get_savegame_variable() const;
    bool is_saved() const;
    bool is_empty() const;

    void ensure_obtainable();
    void give_to_player() const;
    bool is_found() const;

    void draw(Surface& dst_surface, int x, int y);

  private:

    Game* game;                     /**< the current game */
    std::string item_name;          /**< content of the treasure (or an empty string) */
    int variant;                    /**< variant of this content */
    std::string savegame_variable;  /**< name of the savegame boolean variable corresponding to this treasure,
                                     * or an empty string if the treasure state is not saved */
    Sprite* sprite;                 /**< the sprite of the treasure (loaded on demand, NULL until required) */

    void check_obtainable() const;
};

#endif

