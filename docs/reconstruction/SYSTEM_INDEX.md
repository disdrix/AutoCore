# System Index

| System ID | Name | Priority order slot | Status | Map path | Notes |
|-----------|------|---------------------|--------|----------|-------|
| SYS-INPUT-DRIVE | input-drive-control | #1 input / #2 movement | **active / partial** — high priority | `systems/input-drive-control.md` | Primary selection; axis setters + DriveControlTick map |
| SYS-INVENTORY | inventory-transfer | #4 inventory | **active / partial** — high priority | `systems/inventory-transfer.md` | Grab/drop/equip + grid footprint units scaffolded |
| SYS-SKILLS | skills-abilities | # user-triggered actions | **active / partial** — high priority | `systems/skills-abilities.md` | Cast / quick-bar / target validation units scaffolded |
| SYS-MISSION | missions-progression | #7 missions | **active / partial** — high priority | `systems/missions-progression.md` | Grant / prereq / objective / dialog / journal units scaffolded |
| SYS-INTERACT | interaction-activation | #3 interaction | **active / partial** — high priority | `systems/interaction-activation.md` | Primary UseObject send duals refined 2026-07-29 |
| SYS-MOTION-NET | network-vehicle-pose | #2/#13 movement+comms | indexed | see `docs/MOTION_CLIENT_RE.md` | Supporting; not primary |
| SYS-PHYSICS-VEH | physics-vehicle | infrastructure | **deferred** | `physics/README.md` | Deep verified corpus; not primary next |

## Selection rationale

High-priority **active/partial** systems this cycle:

1. **input-drive-control** — user-held action-map flags → vehicle entity drive axes (most advanced unit: `aa_004f5620` dual-reviewed, still not complete).
2. **interaction-activation** — world UseObject C2S `0x2072` send paths + pick/keybind producers (`aa_00916740` / `aa_00930d70` dual-reviewed).
3. **inventory-transfer** — client grab/drop/equip and cargo grid placement.
4. **skills-abilities** — quick-bar / cast request / local validate / targets.
5. **missions-progression** — grant, prerequisites, objectives, dialog, journal.

Physics vehicle internals remain deferred unless required as a dependency for explaining selected high-level behavior. This index does **not** claim full program coverage.
