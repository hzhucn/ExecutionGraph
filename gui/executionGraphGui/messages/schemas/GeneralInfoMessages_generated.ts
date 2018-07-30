// automatically generated by the FlatBuffers compiler, do not modify

import * as NS3867129537019818362 from "./GraphTypeDescription_generated";
/**
 * @constructor
 */
export namespace executionGraphGUI.serialization{
export class GetAllGraphTypeDescriptionsResponse {
  /**
   * @type {flatbuffers.ByteBuffer}
   */
  bb: flatbuffers.ByteBuffer|null = null;

  /**
   * @type {number}
   */
  bb_pos:number = 0;
/**
 * @param {number} i
 * @param {flatbuffers.ByteBuffer} bb
 * @returns {GetAllGraphTypeDescriptionsResponse}
 */
__init(i:number, bb:flatbuffers.ByteBuffer):GetAllGraphTypeDescriptionsResponse {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {GetAllGraphTypeDescriptionsResponse=} obj
 * @returns {GetAllGraphTypeDescriptionsResponse}
 */
static getRootAsGetAllGraphTypeDescriptionsResponse(bb:flatbuffers.ByteBuffer, obj?:GetAllGraphTypeDescriptionsResponse):GetAllGraphTypeDescriptionsResponse {
  return (obj || new GetAllGraphTypeDescriptionsResponse).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {number} index
 * @param {executionGraphGUI.serialization.GraphTypeDescription=} obj
 * @returns {executionGraphGUI.serialization.GraphTypeDescription}
 */
graphsTypes(index: number, obj?:NS3867129537019818362.executionGraphGUI.serialization.GraphTypeDescription):NS3867129537019818362.executionGraphGUI.serialization.GraphTypeDescription|null {
  var offset = this.bb!.__offset(this.bb_pos, 4);
  return offset ? (obj || new NS3867129537019818362.executionGraphGUI.serialization.GraphTypeDescription).__init(this.bb!.__indirect(this.bb!.__vector(this.bb_pos + offset) + index * 4), this.bb!) : null;
};

/**
 * @returns {number}
 */
graphsTypesLength():number {
  var offset = this.bb!.__offset(this.bb_pos, 4);
  return offset ? this.bb!.__vector_len(this.bb_pos + offset) : 0;
};

/**
 * @param {flatbuffers.Builder} builder
 */
static startGetAllGraphTypeDescriptionsResponse(builder:flatbuffers.Builder) {
  builder.startObject(1);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} graphsTypesOffset
 */
static addGraphsTypes(builder:flatbuffers.Builder, graphsTypesOffset:flatbuffers.Offset) {
  builder.addFieldOffset(0, graphsTypesOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {Array.<flatbuffers.Offset>} data
 * @returns {flatbuffers.Offset}
 */
static createGraphsTypesVector(builder:flatbuffers.Builder, data:flatbuffers.Offset[]):flatbuffers.Offset {
  builder.startVector(4, data.length, 4);
  for (var i = data.length - 1; i >= 0; i--) {
    builder.addOffset(data[i]);
  }
  return builder.endVector();
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} numElems
 */
static startGraphsTypesVector(builder:flatbuffers.Builder, numElems:number) {
  builder.startVector(4, numElems, 4);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
static endGetAllGraphTypeDescriptionsResponse(builder:flatbuffers.Builder):flatbuffers.Offset {
  var offset = builder.endObject();
  return offset;
};

}
}