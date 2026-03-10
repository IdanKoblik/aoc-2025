const std = @import("std");

pub fn solve(input: []const u8) !void {
    var lines = std.mem.splitScalar(u8, input, '\n');

    var dial: u32 = 50;
    var part1: u32 = 0;
    var part2: u32 = 0;

    while (lines.next()) |line| {
        if (line.len == 0)
            continue;

        const dir: u8 = line[0];
        const value: u32 = try std.fmt.parseInt(u32, line[1..], 10);

        for (0..value) |_| {
            dial = if (dir == 'L')
                (dial + 99) % 100
            else
                (dial + 1) % 100;

            if (dial == 0)
                part2 += 1;
        }

        if (dial == 0)
            part1 += 1;
    }

    std.debug.print("Part1: {d}\n", .{part1});
    std.debug.print("Part2: {d}\n", .{part2});
}
