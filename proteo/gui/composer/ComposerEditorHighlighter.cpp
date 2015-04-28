
//!
//! \file ComposerEditorHighlighter.cpp
//!
// Copyright 2015 MakingBot
// This file is part of proteo.
//
// proteo is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// proteo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with proteo.  If not, see <http://www.gnu.org/licenses/>.

#include "ComposerEditorHighlighter.hpp"

using namespace proteo;
using namespace proteo::gui;

/* ============================================================================
 *
 * */
ComposerEditorHighlighter::ComposerEditorHighlighter(QTextDocument* document)
    : QSyntaxHighlighter(document)
{
    registerRules();
}

/* ============================================================================
 * Python implementation
 * */
void ComposerEditorHighlighter::registerRules()
{
    HighlightingRule rule;

     QTextCharFormat keywordFormat;
    keywordFormat.setFontWeight(QFont::Bold);
    keywordFormat.setForeground(Qt::darkGreen);

    QStringList keywordPatterns;
    keywordPatterns << "\\bfrom\\b" << "\\bimport\\b";

    foreach (const QString &pattern, keywordPatterns)
    {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        m_highlightingRules.append(rule);
    }

    keywordFormat.setFontWeight(QFont::Bold);
    keywordFormat.setForeground(Qt::darkRed);

    keywordPatterns.clear();
    keywordPatterns << "=";

    foreach (const QString &pattern, keywordPatterns)
    {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        m_highlightingRules.append(rule);
    }
}

/* ============================================================================
 *
 * */
void ComposerEditorHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, m_highlightingRules)
    {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0)
        {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
}


