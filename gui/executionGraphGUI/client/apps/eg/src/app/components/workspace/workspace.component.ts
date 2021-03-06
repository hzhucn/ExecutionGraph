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

import { Component, OnInit, ElementRef, HostListener, Injectable } from '@angular/core';
import { DomSanitizer, SafeStyle } from '@angular/platform-browser';

import { Point } from '@eg/graph';
import { Node } from '../../model/Node';
import { Connection } from '../../model/Connection';
import { Socket } from '../../model/Socket';
import { DragEvent } from '@eg/graph';
import { GraphInfoService } from '../../services/GraphInfoService';

@Injectable() @Component({
  selector: 'eg-workspace',
  templateUrl: './workspace.component.html',
  styleUrls: ['./workspace.component.scss']
})
export class WorkspaceComponent implements OnInit {

  public nodes: Node[] = [];

  public connections: Connection[] = [];

  public newConnection: Connection = null;
  public newConnectionEndpoint: Point = { x: 0, y: 0 };

  constructor(
    private elementRef: ElementRef,
    private sanitizer: DomSanitizer,
    private readonly graphInfoService: GraphInfoService) { }

  ngOnInit() {
    const NODES = 10;

    for (let i = 0; i < NODES; i++) {
      this.generateNode(i);
    }

    for (let i = 0; i < NODES; i++) {
      this.generateRandomConnection();
    }

    // const n1 = new Node('n-1', 'Knoten Uno', [], [new Socket("n-1-o-1", "Some Output with text that is too long")], { x: 100, y: 150 });
    // const n2 = new Node('n-2', 'Knoten Due', [new Socket("n-2-i-1", "Some Input")], [], { x: 300, y: 300 });
    // this.nodes.push(n1);
    // this.nodes.push(n2);

    // this.connections.push(new Connection(n1.outputs[0].id, n2.inputs[0].id));

    // Get some graph info (nicht awaiten ist ja scheissegal zum testen...)
    console.debug("Get all graph type descirptions...")
    this.graphInfoService.getAllGraphTypeDescriptions();
    console.debug("Get all graph type descirptions [done]")

  }

  public updateNodePosition(node: Node, event: DragEvent) {
    // console.log(`[WorkspaceComponent] Updating node position to ${position.x}:${position.y}`);
    node.uiProps.x = event.dragElementPosition.x;
    node.uiProps.y = event.dragElementPosition.y;
  }

  public initConnectionFrom(socket: Socket, event: DragEvent) {
    console.log(`[WorkspaceComponent] Initiating new connection from ${socket.id}`);
    this.newConnection = new Connection(socket.id, "tempTarget");
    this.newConnectionEndpoint = {
      x: event.dragElementPosition.x + event.mouseToElementOffset.x,
      y: event.dragElementPosition.y + event.mouseToElementOffset.y
    };
  }

  public movingConnection(event: DragEvent) {
    this.newConnectionEndpoint = {
      x: event.dragElementPosition.x + event.mouseToElementOffset.x,
      y: event.dragElementPosition.y + event.mouseToElementOffset.y
    };
    // console.log(`Setting position to ${this.newConnectionEndpoint.x}:${this.newConnectionEndpoint.y}`)
  }

  public createConnection() {
    this.newConnection = null;
  }

  private generateNode(id: number) {
    const x = Math.random() * this.elementRef.nativeElement.offsetWidth / 2;
    const y = Math.random() * this.elementRef.nativeElement.offsetHeight / 2;
    this.nodes.push(new Node(`n${id}`, `Some test node ${id}`, [new Socket(`n-${id}-i-1`, "Some Input")], [new Socket(`n-${id}-o-1`, "Some Output with text that is too long")], { x: x, y: y }));
  }

  private generateRandomConnection() {
    let source = this.nodes[Math.round(Math.random() * (this.nodes.length - 1))].outputs[0];
    let target = this.nodes[Math.round(Math.random() * (this.nodes.length - 1))].inputs[0];
    if (source !== target) {
      this.connections.push(new Connection(source.id, target.id));
    }
  }

}
