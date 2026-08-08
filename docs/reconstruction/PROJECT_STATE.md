# Project State — Client Verified Decompilation

| Field | Value |
|-------|-------|
| Target binary | `autoassault.exe` |
| Ghidra program | `autoassault.exe` (open) |
| Image base | `0x400000` |
| Language | x86:LE:32:default / windows |
| Function count (live `list_functions_enhanced`) | **25671** |
| Function count (`get_function_count` MCP) | **26263** (inflated; not terminal sizing) |
| Inventory listed / accounted | **25671** / **true** |
| Dual A/B unique (filesystem recount) | **2726** |
| Inventory `reviewed` | **2726** (= dual A∩B after WQ-AUDIT-002) |
| Terminal accounting | **true** (list_functions universe stamp only) |
| Dual depth complete | **false** (~10.6%) |
| Runtime / differential | **false** / open |
| Primary write surface | `docs/reconstruction/**` |
| Last updated | 2026-08-05 (R13 sealed + WQ-AUDIT-002; CAP-004 freeze) |
| **Audit rating** | **PARTIAL FAILURE** |

## Mission

Recover high-level, externally observable client behavior as evidence-backed, readable reconstructions. Accuracy over throughput. Never erase prior useful analysis.

## Honesty banners (mandatory — audit)

1. **`full` / `terminal_full_coverage` / inventory accounted** means every live listed VA is stamped `full` | `reviewed` | `trivial-batch` (or deferred-low). It does **not** mean dual-reviewed, runtime-confirmed, or maintainable product reconstruction.
2. **~81%** of function records are still **Partial scaffold** (industrial three-rep). Treat as raw coverage, not verified behavior.
3. **Dual A∩B 2726** is deep-review count; inventory `reviewed=2726` matches after WQ-AUDIT-002 bulk promote (still ≪ 25671).
4. **Runtime Confirmed = false** for the program. No unit is complete solely from dual accept-with-gaps.
5. **Residual STL dual volume waves are frozen** (CAP-004) until process P0 items land.

See: `docs/reconstruction/audits/CURRENT_AUDIT.md`.

## Current focus

| Item | Value |
|------|-------|
| Active wave | **Verification-first** — CAP freeze + no coverage-metric optimization |
| Dual depth | 2726 ≪ 25671 (byproduct only; not a goal) |
| Runtime / differential | Open (no Launcher without approval) |
| Bit-for-bit | Deferred |

## Status snapshot

| Area | Status |
|------|--------|
| Inventory terminal statuses | **accounted** (none/raw/partial=0) — **not** verified depth |
| HP dualed managers | **partial** static quality generally holds under audit sample |
| Industrial full corpus | **scaffold** — not dual-verified |
| System maps | missions / inventory / skills / interaction / input (all partial, runtime open) |
| Runtime | blocked without Launcher approval |
| Process integrity | **PARTIAL FAILURE** — metrics/vocabulary/priority drift |

## Resume

See `RESUME.md` and `audits/CORRECTIVE_ACTION_PLAN.md`.
