# Wave 5 — CRT / import trivial-batch expansion (body-proven)

| Field | Value |
|-------|-------|
| Date | 2026-07-29 |
| Owner | meta CRT/import trivial-batch |
| Ledger | [`docs/reconstruction/coverage/trivial_batch_imports.jsonl`](../coverage/trivial_batch_imports.jsonl) |
| Prior import rows | **9** |
| **Count added this pass** | **112** |
| Ledger total after | **121** |

## Scope

Body-prove CRT/API names already present under `docs/reconstruction/functions/` (and related Direct3D / acm / WSA / ov / nci stubs) as **pure IAT import thunks**, **jump-to-IAT**, or **tiny CRT/runtime** bodies. Append only accepts to the import trivial-batch ledger.

**Not done:** domain managers, PE `entry`, ATL helpers with real local logic, generic non-IAT `FUN_*` plates.

## Method

1. Enumerate function records in `0x004898xx`–`0x00489fff` plus named import families (`Direct3D*`, `D3DX*`, `acm*`, `WSA*`, `ov_*`, `nci*`, CRT symbols).
2. Read authoritative raw decompiles under `docs/reconstruction/raw/aa_*.md`.
3. Accept when body shows:
   - Ghidra “Treating indirect jump as call” / unrecovered jumptable (IAT thunk), **or**
   - `Library Function - Single Match` tiny CRT/runtime (VS2003-class), **or**
   - SEH vector cleanup that only calls `__ArrayUnwind`, **or**
   - tiny `free` forwarder at `0x00703150`.
4. Prefer decompiler-recovered CRT names for former `FUN_*` IAT slots (e.g. `fopen`, `memmove`, `wcslen`).
5. Append `{addr,name,status,reason}` rows; do not rewrite the pre-existing 9 CRT helper rows.

## Counts by class (added)

| Class | Count |
|-------|------:|
| CRT/API pure IAT (0x004898–0x00489d block + scattered) | 34 |
| Tiny CRT/runtime (VS Single Match / SEH helpers) | 10 |
| Direct3D / D3DX IAT | 22 |
| acm IAT | 12 |
| WSA IAT | 5 |
| ov_* IAT | 8 |
| nci IAT | 13 |
| CRT free forwarder (`0x00703150`) | 1 |
| **Total added** | **112** |

## Named CRT samples body-proven as IAT

| Addr | Name | Body pattern |
|------|------|--------------|
| `0x0048982e` | `strncmp` | indirect jump → IAT |
| `0x0048983a` | `fclose` | indirect jump → IAT |
| `0x00489840` | `fprintf` | indirect jump → IAT |
| `0x0048989e` | `_snprintf` | indirect jump → IAT |
| `0x004898aa` | `sscanf` | indirect jump → IAT |
| `0x004898f4` | `free` | indirect jump → IAT |
| `0x00489912` | `tolower` | indirect jump → IAT |
| `0x0048991e` | `ceil` | indirect jump → IAT |
| `0x00489a44` | `isalnum` | indirect jump → IAT |
| `0x00489a4a` | `floor` | indirect jump → IAT |
| `0x00489cc2` | `exit` | indirect jump → IAT |
| `0x00489d72` | `_controlfp` | indirect jump → IAT |
| `0x00489e70` | `Direct3DCreate9` | indirect jump → IAT |
| `0x00717e10` | `acmDriverClose` | indirect jump → IAT |

## Tiny CRT samples (not pure JMP, still trivial)

| Addr | Name | Reason |
|------|------|--------|
| `0x004898d6` | `_atexit` | VS Single Match wrapper → `__onexit` |
| `0x00489924` | `_eh_vector_constructor_iterator_` | VS EH vector ctor iterator |
| `0x00489986` | `__ArrayUnwind` | VS array unwind |
| `0x00489c64` | `__SEH_prolog` | inlined SEH prolog |
| `0x00489c9f` | `__SEH_epilog` | inlined SEH epilog |
| `0x00489d5c` | `__setdefaultprecision` | calls `_controlfp` only |

## Explicit excludes

| Addr / class | Why excluded |
|--------------|--------------|
| `0x00489a56` `entry` | Full CRT PE startup — not pure thunk |
| `FUN_00489d78` / `FUN_00489daf` ATL | Local ATL array/module logic |
| Domain managers (`CVOG*`, `Client_*`, skills, missions, …) | Never trivial-batch |
| Pre-existing 9 ledger rows (`__chkstk`, `__alldiv`, …) | Already accounted |

## Inventory stamp note

Ran `docs/reconstruction/coverage/stamp_inventory_status.py` after ledger update.

**Expected behavior:** addresses that already have `functions/` or `raw/` artifacts remain inventory status **`full`** (stamp prefers artifact presence over trivial-batch). Durable trivial-batch accounting for this pass is the **import JSONL side ledger**, not a mass `status=trivial-batch` rewrite of artifact-bearing CRT rows. That matches prior wave audit policy.

## Result

| Metric | Value |
|--------|------:|
| **Added to `trivial_batch_imports.jsonl`** | **112** |
| Prior + added = total import ledger rows | 9 + 112 = **121** |
