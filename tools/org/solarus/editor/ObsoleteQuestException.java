/*
 * Copyright (C) 2006-2013 Christopho, Solarus - http://www.solarus-games.org
 *
 * Solarus Quest Editor is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Solarus Quest Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
package org.solarus.editor;

/**
 * Exception thrown if the quest has an obsolete format.
 */
public class ObsoleteQuestException extends QuestEditorException {

    /**
     * The problematic quest format.
     */
    private String questFormat;

    /**
     * Constructor.
     * @param questFormat Format of the quest.
     */
    public ObsoleteQuestException(String questFormat) {
        super("The format of this quest (" + questFormat
                + ") is obsolete.\nPlease upgrade your quest data files to Solarus "
                + Project.solarusFormat + ".");
        this.questFormat = questFormat;
    }

    /**
     * Returns the format of the quest.
     * @return The format of the quest.
     */
    public String getQuestFormat() {
        return questFormat;
    }
}

