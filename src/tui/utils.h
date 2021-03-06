//
// Created by dan on 29/04/2020.
//

#ifndef TUITUBE_UTILS_H
#define TUITUBE_UTILS_H

#include "../invidious/video.h"

namespace tui::utils {
        static void print_title(const std::string& title, int width, const std::string& extra = "") {
            terminal::set_background_color(terminal::e_color::white);
            terminal::set_text_color(terminal::e_color::black);

            std::string formatted_title = title;

            if (!extra.empty())
                formatted_title = formatted_title + " - " + extra; // += doesn't work?

            if (formatted_title.size() > width)
                formatted_title = formatted_title.substr(0, width - 3) + "...";

            printf("%s", formatted_title.c_str());

            for (int i = 0; i < width - formatted_title.length(); i++)
                printf("%s", " "); // formatted_title += adds the incorrect number?

            terminal::reset();
        }

        static void print_videos(const std::vector<invidious::c_video>& videos,
                int selected, int width, int height, int scroll) {
            int max = std::min(height + scroll - 1, static_cast<int>(videos.size()));
            for (int i = scroll; i < max; i++) {
                const auto &video = videos[i];

                if (i == selected) {
                    terminal::set_background_color(terminal::e_color::white);
                    terminal::set_text_color(terminal::e_color::black);
                }

                std::string text = video.channel_name + " - " + video.title;
                if (text.size() > width)
                    text = text.substr(0, width - 3) + "...";

                printf("%s", text.c_str());
                for (int i = 0; i < width - text.length(); i++)
                    printf("%s", " ");
                if (i != max - 1)
                    printf("%s", "\n");

                if (i == selected)
                    terminal::reset();
            }
        }

        static void print_footer(const std::string& binds, int width) {
            terminal::set_background_color(terminal::e_color::white);
            terminal::set_text_color(terminal::e_color::black);

            printf("%s", "\n");

            if (binds.size() > width)
                printf("%s", binds.substr(0, width - 3).c_str(), "...");
            else {
                printf("%s", binds.c_str());

                for (int i = 0; i < width - binds.length(); i++)
                    printf("%s", " ");
            }

            terminal::reset();
        }
    }

#endif //TUITUBE_UTILS_H
