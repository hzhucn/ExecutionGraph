// =========================================================================================
//  ExecutionGraph
//  Copyright (C) 2014 by Gabriel Nützi <gnuetzi (at) gmail (døt) com>
//
//  @date Sun Jul 29 2018
//  @author Simon Spoerri, simon (døt) spoerri (at) gmail (døt) com
//
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at http://mozilla.org/MPL/2.0/.
// =========================================================================================

import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { GraphComponent } from '@eg/graph/src/components/graph/graph.component';
import { PortComponent } from '@eg/graph/src/components/port/port.component';
import { ConnectionComponent } from '@eg/graph/src/components/connection/connection.component';
import { DraggableDirective } from '@eg/graph/src/directives/draggable.directive';

@NgModule({
  imports: [CommonModule],
  declarations: [GraphComponent, PortComponent, ConnectionComponent, DraggableDirective],
  exports: [GraphComponent, PortComponent, ConnectionComponent, DraggableDirective]
})
export class GraphModule {}
