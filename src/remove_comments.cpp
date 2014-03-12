#include <string>
#include <algorithm>


using namespace std;


void removeCommentsFrom(string &line, bool &isMultilineCommentBody)
{
    const char M = '\0';

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
            line[i] = M;
        }
        else if (isMultilineCommentBody) {
            line[i] = M;

            if (line.substr(i + 1, 2) == "*/") {
                line[i + 1] = M;
                line[i + 2] = M;
                isMultilineCommentBody = false;
            }
        }
    }

    line.erase(remove(line.begin(), line.end(), M), line.end());
}
