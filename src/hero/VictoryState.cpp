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
#include "hero/VictoryState.h"
#include "hero/FreeState.h"
#include "hero/HeroSprites.h"
#include "lua/LuaContext.h"
#include "lowlevel/System.h"
#include "lowlevel/Sound.h"
#include "Game.h"
#include "Map.h"

/**
 * \brief Constructor.
 * \param hero The hero controlled by this state.
 * \param callback_ref Lua ref to a function to call when the
 * victory sequence finishes (possibly LUA_REFNIL).
 */
Hero::VictoryState::VictoryState(Hero& hero, int callback_ref):
  State(hero, "victory"),
  end_victory_date(0),
  finished(false),
  callback_ref(callback_ref) {

}

/**
 * \brief Destructor.
 */
Hero::VictoryState::~VictoryState() {

}

/**
 * \brief Starts this state.
 * \param previous_state the previous state
 */
void Hero::VictoryState::start(State* previous_state) {

  State::start(previous_state);

  get_sprites().set_animation_victory();
  get_sprites().set_ignore_suspend(true);
  Sound::play("victory");

  // compute the date when the victory state is considered as finished,
  // but the game may be currently suspended
  uint32_t start_victory_date = suspended ? when_suspended : System::now();
  end_victory_date = start_victory_date + 1500;
}

/**
 * \brief Stops this state.
 * \param next_state the next state
 */
void Hero::VictoryState::stop(State* next_state) {

  State::stop(next_state);
  get_sprites().set_ignore_suspend(false);
  get_lua_context().cancel_callback(callback_ref);
  callback_ref = LUA_REFNIL;
}

/**
 * \brief Updates this state.
 */
void Hero::VictoryState::update() {

  State::update();

  if (!finished && System::now() >= end_victory_date) {
    finished = true;
    if (callback_ref != LUA_REFNIL) {
      // The behavior is defined by Lua.
      int callback_ref = this->callback_ref;
      this->callback_ref = LUA_REFNIL;
      get_lua_context().do_callback(callback_ref);
    }
    else {
      // By default, get back to the normal state.
      hero.set_state(new FreeState(hero));
    }
  }
}

/**
 * \brief Notifies this state that the game was just suspended or resumed.
 * \param suspended true if the game is suspended
 */
void Hero::VictoryState::set_suspended(bool suspended) {

  State::set_suspended(suspended);

  if (!suspended) {
    end_victory_date += System::now() - when_suspended;
  }
}

