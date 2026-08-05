# Decision Log

| Date | Decision ID | Decision | Rationale | Alternatives rejected |
|------|-------------|----------|-----------|----------------------|
| 2026-07-23 | DEC-001 | Select **input-drive-control** as primary system | Objective priority order #1 user input; clear entry `DriveControlTick`; high user impact | Physics-first continuation (lower default priority); inventory-first (priority #4, after input) |
| 2026-07-23 | DEC-002 | Important unit = **SetSteerInput** `0x004f5620` not full DriveControlTick | Small, fully checkable CF; central axis write; DriveControlTick too large for one verified unit bar | Reconstructing entire DriveControlTick as “one unit” (would leave verification theater) |
| 2026-07-23 | DEC-003 | Keep Ghidra symbol names when they match behavior | Avoid inventing original architecture/names | Cosmetic renames without evidence |
| 2026-07-23 | DEC-004 | Runtime/diff remain open | No Launcher without approval; no live client experiment this run | Fabricating runtime evidence (forbidden) |
| 2026-07-23 | DEC-005 | Physics corpus deferred not deleted | Preserve prior art; index only | Mass rewrite of physics verified notes |
| 2026-07-23 | DEC-006 | Prefer suppress-gate naming over “lock” | Skeptical review: mask proven, lock semantics not | Sealing “steer lock” without producers |
| 2026-07-23 | DEC-007 | Unit remains partial after dual reviews | Runtime/diff/type gaps; practical bar met for goal | Marking complete despite open dims |
| 2026-08-04 | DEC-W37-001 | Wave37 selects high-mention nested callees of dualed managers (+ W36-K residual) | HP entry duals already present; dual depth expansion is next highest durable value without Launcher | Re-dual HP managers; invent runtime evidence |
| 2026-08-04 | DEC-W37-002 | ADV-correct stage-2 WireColor on `0x0098df00` to **(0,1,0,0.5)** | Independent ADV re-decompile falsified dual prose blue wire; clean twin assigns already matched binary | Leave false seal; change clean twin assignments |
| 2026-08-04 | DEC-W38-001 | ADV-correct `phyBoundingBox_Unserialize` float3 stream order to **+0x14→+0x20→+0x00** | Live LEAs falsified dual A→B→C stream order; field layout map still correct | Leave wrong port order |
