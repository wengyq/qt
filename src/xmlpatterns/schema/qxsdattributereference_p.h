/****************************************************************************
**
** Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtXmlPatterns of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the either Technology Preview License Agreement or the
** Beta Release License Agreement.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://www.qtsoftware.com/contact.
** $QT_END_LICENSE$
**
****************************************************************************/

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef Patternist_XsdAttributeReference_H
#define Patternist_XsdAttributeReference_H

#include "qxsdattributeuse_p.h"

#include <QtXmlPatterns/QSourceLocation>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short A helper class for attribute reference resolving.
     *
     * For easy resolving of attribute references, we have this class
     * that can be used as a place holder for the real attribute use
     * object it is referring to.
     * So whenever the parser detects an attribute reference, it creates
     * a XsdAttributeReference and returns it instead of the XsdAttributeUse.
     * During a later phase, the resolver will look for all XsdAttributeReferences
     * in the schema and will replace them with their referring XsdAttributeUse
     * objects.
     *
     * @ingroup Patternist_schema
     * @author Tobias Koenig <tobias.koenig@trolltech.com>
     */
    class XsdAttributeReference : public XsdAttributeUse
    {
        public:
            typedef QExplicitlySharedDataPointer<XsdAttributeReference> Ptr;

            /**
             * Describes the type of the attribute reference.
             */
            enum Type
            {
                AttributeUse,   ///< The reference points to an attribute use.
                AttributeGroup  ///< The reference points to an attribute group.
            };

            /**
             * Always returns false, used to avoid dynamic casts.
             */
            virtual bool isAttributeUse() const;

            /**
             * Always returns true, used to avoid dynamic casts.
             */
            virtual bool isReference() const;

            /**
             * Sets the @p type of the attribute reference.
             */
            void setType(Type type);

            /**
             * Returns the type of the attribute reference.
             */
            Type type() const;

            /**
             * Sets the @p name of the attribute or attribute group the
             * attribute reference refers to.
             */
            void setReferenceName(const QXmlName &name);

            /**
             * Returns the name of the attribute or attribute group the
             * attribute reference refers to.
             */
            QXmlName referenceName() const;

            /**
             * Sets the source @p location where the reference is located.
             */
            void setSourceLocation(const QSourceLocation &location);

            /**
             * Returns the source location where the reference is located.
             */
            QSourceLocation sourceLocation() const;

        private:
            Type            m_type;
            QXmlName        m_referenceName;
            QSourceLocation m_sourceLocation;
    };
}

QT_END_NAMESPACE

QT_END_HEADER

#endif