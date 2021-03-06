/***************************************************************************
                             qgssqliteexpressioncompiler.h
                             ---------------------------------
    begin                : November 2015
    copyright            : (C) 2015 Nyall Dawson
    email                : nyall dot dawson at gmail dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSSQLITEEXPRESSIONCOMPILER_H
#define QGSSQLITEEXPRESSIONCOMPILER_H

#define SIP_NO_FILE

///@cond PRIVATE

#include "qgis_core.h"
#include "qgssqlexpressioncompiler.h"

/**
 * \ingroup core
 * \class QgsSQLiteExpressionCompiler
 * \brief Expression compiler for translation to SQlite SQL WHERE clauses.
 *
 * This class is designed to be used by SpatiaLite and OGR providers.
 * \note Not part of stable API, may change in future versions of QGIS
 * \note Not available in Python bindings
 * \since QGIS 2.16
 */

class CORE_EXPORT QgsSQLiteExpressionCompiler : public QgsSqlExpressionCompiler
{
  public:

    /**
     * Constructor for expression compiler.
     * \param fields fields from provider
     */
    explicit QgsSQLiteExpressionCompiler( const QgsFields &fields );

  protected:

    Result compileNode( const QgsExpressionNode *node, QString &str ) override;
    QString quotedIdentifier( const QString &identifier ) override;
    QString quotedValue( const QVariant &value, bool &ok ) override;
    QString sqlFunctionFromFunctionName( const QString &fnName ) const override;
    QString castToReal( const QString &value ) const override;
    QString castToInt( const QString &value ) const override;

};

///@endcond

#endif // QGSSQLITEEXPRESSIONCOMPILER_H
