const std = @import("std");
const day01 = @import("days/day01.zig");
const input = @import("util/input.zig");
const aoc_2025 = @import("aoc_2025");

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();

    const data = try input.readFile(allocator, "inputs/day01.txt");
    defer allocator.free(data);

    try day01.solve(data);
}
