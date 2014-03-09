
#ifndef REMOVE_COMMENTS_H
#define REMOVE_COMMENTS_H


#include <string>
#include <algorithm>


using std::string;
using std::remove;



void removeCommentsFrom(string &line, bool &isMultilineCommentBody)
{
    bool isInlineCommentBody = false;

    for (size_t i = 0; i < line.length(); ++i) {
        if (!isInlineCommentBody && !isMultilineCommentBody) {
            if (line.substr(i, 2) == "//") {
                isInlineCommentBody = true;
            }
            else if (line.substr(i, 2) == "/*") {
                isMultilineCommentBody = true;
            }
        }

        if (isInlineCommentBody) {
            line[i] = '@';
        }
        else if (isMultilineCommentBody) {
            line[i] = '@';

            if (line.substr(i + 1, 2) == "*/") {
                line[i + 1] = '@';
                line[i + 2] = '@';
                isMultilineCommentBody = false;
            }
        }
    }


    line.erase(remove(line.begin(), line.end(), '@'), line.end());
}


#endif
