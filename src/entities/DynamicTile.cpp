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
#include "entities/DynamicTile.h"
#include "entities/Tileset.h"
#include "entities/TilePattern.h"
#include "entities/Hero.h"
#include "lowlevel/FileTools.h"
#include "lowlevel/Debug.h"
#include "Game.h"
#include "Map.h"

/**
 * \brief Creates a new dynamic tile on the map.
 * \param name a name to identify this tile
 * \param layer layer of the tile
 * \param x x position of the tile on the map
 * \param y y position of the tile on the map
 * \param width width of the tile (the pattern can be repeated)
 * \param height height of the tile (the pattern can be repeated)
 * \param tile_pattern_id id of the tile pattern in the tileset
 * \param enabled true to make the tile active on the map
 */
DynamicTile::DynamicTile(const std::string& name, Layer layer, int x, int y,
			 int width, int height, int tile_pattern_id, bool enabled):
  MapEntity(name, 0, layer, x, y, width, height),
  tile_pattern_id(tile_pattern_id),
  tile_pattern(NULL) {

  set_enabled(enabled);
}

/**
 * \brief Destructor.
 */
DynamicTile::~DynamicTile() {

}

/**
 * \brief Returns the type of entity.
 * \return the type of entity
 */
EntityType DynamicTile::get_type() const {

  return ENTITY_DYNAMIC_TILE;
}

/**
 * \brief Sets the map of this entity.
 *
 * Warning: as this function is called when initializing the map,
 * the current map of the game is still the old one.
 *
 * \param map the map
 */
void DynamicTile::set_map(Map &map) {

  MapEntity::set_map(map);
  this->tile_pattern = &map.get_tileset().get_tile_pattern(tile_pattern_id);
}

/**
 * \brief Returns whether entities of this type can override the ground
 * of where they are placed.
 * \return \c true if this type of entity can change the ground.
 */
bool DynamicTile::is_ground_modifier() const {
  return true;
}

/**
 * \brief When is_ground_modifier() is \c true, returns the ground defined
 * by this entity.
 * \return The ground defined by this entity.
 */
Ground DynamicTile::get_modified_ground() const {
  return tile_pattern->get_ground();
}

/**
 * \brief Returns whether this tile is an obstacle for the specified entity.
 * \param other an entity
 * \return true if this tile is an obstacle for the entity
 */
bool DynamicTile::is_obstacle_for(MapEntity& other) {

  // TODO normally, this function can be removed since there is already
  // a modified ground
  bool result = false;
  switch (get_modified_ground()) {

    case GROUND_WALL:
    case GROUND_LOW_WALL:
    case GROUND_WALL_TOP_RIGHT:
    case GROUND_WALL_TOP_LEFT:
    case GROUND_WALL_BOTTOM_LEFT:
    case GROUND_WALL_BOTTOM_RIGHT:
    case GROUND_WALL_TOP_RIGHT_WATER:
    case GROUND_WALL_TOP_LEFT_WATER:
    case GROUND_WALL_BOTTOM_LEFT_WATER:
    case GROUND_WALL_BOTTOM_RIGHT_WATER:
      result = true;
      break;

    case GROUND_EMPTY:
    case GROUND_TRAVERSABLE:
    case GROUND_SHALLOW_WATER:
    case GROUND_DEEP_WATER:
    case GROUND_GRASS:
    case GROUND_HOLE:
    case GROUND_LAVA:
    case GROUND_PRICKLE:
    case GROUND_LADDER:
    case GROUND_ICE:
      result = false;
      break;
  }
  return result;
}

/**
 * \brief Draws the tile on the map.
 */
void DynamicTile::draw_on_map() {

  if (!is_drawn()) {
    return;
  }

  const Rectangle& camera_position = get_map().get_camera_position();
  Rectangle dst(0, 0);

  Rectangle dst_position(get_top_left_x() - camera_position.get_x(),
      get_top_left_y() - camera_position.get_y(),
      get_width(), get_height());

  tile_pattern->fill_surface(get_map().get_visible_surface(), dst_position,
      get_map().get_tileset(), camera_position);
}

