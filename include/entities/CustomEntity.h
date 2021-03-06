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
#ifndef SOLARUS_CUSTOM_ENTITY_H
#define SOLARUS_CUSTOM_ENTITY_H

#include "Common.h"
#include "entities/Detector.h"

/**
 * \brief A map entity fully controlled by Lua.
 *
 * A custom entity may have a model, which is the name of a Lua script
 * that controls it. This is useful to make several custom entities with the
 * same behavior more easily.
 */
class CustomEntity: public Detector {

  public:

    CustomEntity(
        Game& game,
        const std::string& name,
        Layer layer,
        int x,
        int y,
        int width,
        int height,
        const std::string& model);
    ~CustomEntity();

    EntityType get_type() const;

    const std::string& get_model() const;

    /* TODO
    bool can_be_obstacle();
    bool is_ground_observer() const;
    const Rectangle get_ground_point() const;
    bool is_ground_modifier() const;
    Ground get_modified_ground() const;
    bool can_be_drawn();
    bool is_drawn_in_y_order();
    bool is_drawn_at_its_position() const;
    const Rectangle get_facing_point() const;
    const Rectangle get_facing_point(int direction) const;

    void notify_map_started();
    void notify_map_opening_transition_finished();
    void notify_tileset_changed();
    void notify_being_removed();
    void notify_enabled(bool enabled);
    void notify_obstacle_reached();
    void notify_position_changed();
    void notify_layer_changed();
    void notify_ground_below_changed();
    void notify_movement_changed();
    void notify_movement_finished();
    void notify_facing_entity_changed(Detector* facing_entity);
    bool has_layer_independent_collisions() const;
    void notify_collision_with_enemy(Enemy& enemy);
    void notify_collision_with_destructible(Destructible& destructible, CollisionMode collision_mode);
    void notify_collision_with_teletransporter(Teletransporter& teletransporter, CollisionMode collision_mode);
    void notify_collision_with_conveyor_belt(ConveyorBelt& conveyor_belt, int dx, int dy);
    void notify_collision_with_stairs(Stairs& stairs, CollisionMode collision_mode);
    void notify_collision_with_jumper(Jumper& jumper, CollisionMode collision_mode);
    void notify_collision_with_sensor(Sensor& sensor, CollisionMode collision_mode);
    void notify_collision_with_switch(Switch& sw, CollisionMode collision_mode);
    void notify_collision_with_switch(Switch& sw, Sprite& sprite_overlapping);
    void notify_collision_with_crystal(Crystal& crystal, CollisionMode collision_mode);
    void notify_collision_with_crystal(Crystal& crystal, Sprite& sprite_overlapping);
    void notify_collision_with_chest(Chest& chest);
    void notify_collision_with_block(Block& block);
    void notify_collision_with_separator(Separator& separator, CollisionMode collision_mode);
    void notify_collision_with_bomb(Bomb& bomb, CollisionMode collision_mode);
    void notify_collision_with_explosion(Explosion& explosion, CollisionMode collision_mode);
    void notify_collision_with_explosion(Explosion& explosion, Sprite& sprite_overlapping);
    void notify_collision_with_fire(Fire& fire, Sprite& sprite_overlapping);
    void notify_collision_with_enemy(Enemy& enemy, Sprite& enemy_sprite, Sprite& this_sprite);
    void notify_attacked_enemy(EnemyAttack attack, Enemy& victim,
        EnemyReaction::Reaction& result, bool killed);
    bool is_obstacle_for(MapEntity& other);
    bool is_low_wall_obstacle();
    bool is_shallow_water_obstacle();
    bool is_deep_water_obstacle();
    bool is_hole_obstacle();
    bool is_lava_obstacle();
    bool is_prickle_obstacle();
    bool is_ladder_obstacle();
    bool is_hero_obstacle(Hero& hero);
    bool is_block_obstacle(Block& block);
    bool is_teletransporter_obstacle(Teletransporter& teletransporter);
    bool is_conveyor_belt_obstacle(ConveyorBelt& conveyor_belt);
    bool is_stairs_obstacle(Stairs& stairs);
    bool is_sensor_obstacle(Sensor& sensor);
    bool is_switch_obstacle(Switch& sw);
    bool is_raised_block_obstacle(CrystalBlock& raised_block);
    bool is_crystal_obstacle(Crystal& crystal);
    bool is_npc_obstacle(NPC& npc);
    bool is_enemy_obstacle(Enemy& enemy);
    bool is_jumper_obstacle(Jumper& jumper);
    bool is_destructible_obstacle(Destructible& destructible);
    bool is_separator_obstacle(Separator& separator);
    bool is_sword_ignored();
    void set_suspended(bool suspended);
    void update();
    void draw_on_map();

    virtual void notify_action_command_pressed();
    virtual bool interaction_with_item(EquipmentItem& item);
    virtual bool start_movement_by_hero();
    virtual void stop_movement_by_hero();
    virtual std::string get_sword_tapping_sound();
    virtual bool test_collision_custom(MapEntity& entity);
*/

  private:

    const std::string& model;          /**< Model of this custom entity, or an empty string. */

};

#endif

