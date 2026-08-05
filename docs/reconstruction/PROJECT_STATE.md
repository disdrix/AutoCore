# Project State — Client Verified Decompilation

| Field | Value |
|-------|-------|
| Target binary | `autoassault.exe` |
| Ghidra program | `autoassault.exe` (open) |
| Image base | `0x400000` |
| Language | x86:LE:32:default / windows |
| Function count (Ghidra) | **~26256** |
| Durable reconstruction units | **~36** (raw + annotated + clean + function record class) |
| Coverage claim | **Incomplete** — 36 ≪ 26256; full-coverage goal not met |
| Primary write surface | `docs/reconstruction/**` |
| Goal mode | Continuous high-priority manager wave toward eventual full coverage |
| Last updated | 2026-08-04 (WQ-007 residual dual seal; dual unique 2209) |

## Mission

Recover high-level, externally observable client behavior as evidence-backed, readable reconstructions. Accuracy over throughput. Never erase prior useful analysis. Expand until every address is accounted (`full` / `reviewed` / `trivial-batch` / explicit deferred-low) — **not yet**.

## Current focus

| Item | Value |
|------|-------|
| Active wave | **WQ-007 residual dual seal complete** (+16; dual 2209); next WQ-008/009 residual or runtime when Launcher approved |
| Priority scores | Missions 96 → Inventory 94 → Skills 93 |
| Parked partial | input-drive-control: WQ-001..003 (SetSteerInput reviewed; SetLongitudinalInput artifacts partial; runtime open) |
| Why not physics-first | Existing physics RE under `physics/` is valuable but **deferred** (WQ-PHY) unless a selected high-level behavior depends on it |
| Why not claim done | Inventory 25664 accounted ≠ full verified depth; runtime/diff open; ~26k functions remain beyond deep units |

## Status snapshot

| Area | Status |
|------|--------|
| Durable state files | Bootstrapped |
| Prior art index | Indexed (physics preserved, deferred) |
| System maps | `missions-progression`, `inventory-transfer`, `skills-abilities`, `input-drive-control`, **`interaction-activation`** |
| Manager scaffolds | deep dual units expanded; collect bridge + interact + modal pairing + ValidateTarget this wave |
| Input unit | SetSteerInput dual reviews done; SetLongitudinalInput partial artifacts |
| Runtime / differential | Open (no Launcher without approval) |
| Full binary coverage | **No** (deep units ≪ 26256; inventory stamp separate) |

## Resume

See `RESUME.md` for exact next action (runtime matrix / inventory cross-links / skill residual naming).
