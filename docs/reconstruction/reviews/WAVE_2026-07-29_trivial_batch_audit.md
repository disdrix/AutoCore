# Trivial-batch coverage audit (2026-07-29)

| Field | Value |
|-------|-------|
| Wave | trivial-batch audit (OWN ONLY) |
| Date | 2026-07-29 |
| Method | Python line counts + JSON parse of inventory/ledgers under workspace `C:\Users\josh\Documents\GitHub\AutoCore` |
| Scope | Report only — **no** inventory restamp, **no** `WORK_QUEUE` / `RESUME` edits |
| Policy | **Do not invent** `trivial-batch` for non-thunk / non-compiler units |

## Ledger counts (authoritative for this pass)

Paths under `docs/reconstruction/coverage/`.

| File | Non-empty JSONL lines | Notes |
|------|----------------------:|-------|
| `trivial_batch_unwind.jsonl` | **8508** | SEH helpers only |
| `trivial_batch_imports.jsonl` | **9** | CRT / helper stubs (see list below) |
| `inventory.jsonl` | **25664** | One row per listed function |

### Unwind ledger split

Parsed `name` prefixes inside `trivial_batch_unwind.jsonl` (no duplicates by `addr`):

| Name class | Count |
|------------|------:|
| `Unwind@*` | **7837** |
| `Catch@*` | **671** |
| Other | **0** |
| **Total** | **8508** |

Row shape (sample):

```json
{"addr": "0x00401792", "name": "Catch@00401792", "status": "trivial-batch", "reason": "SEH unwind/catch helper"}
```

Matches policy in `coverage/TRIVIAL_BATCH.md` (Unwind@ + Catch@ batch).

### Import ledger (all 9 rows)

Parsed from `trivial_batch_imports.jsonl` (unique addrs: 9; overlap with unwind ledger: **0**):

| Addr | Name | Reason |
|------|------|--------|
| `0x006a3d0f` | `__security_check_cookie` | import thunk / CRT / external stub |
| `0x006a3d70` | `__chkstk` | import thunk / CRT / external stub |
| `0x006a3e40` | `__allrem` | import thunk / CRT / external stub |
| `0x006a3f00` | `__alldiv` | import thunk / CRT / external stub |
| `0x006a3fb0` | `__allmul` | import thunk / CRT / external stub |
| `0x006a4062` | `__security_error_handler` | import thunk / CRT / external stub |
| `0x00717e82` | `__WSAFDIsSet` | import thunk / CRT / external stub |
| `0x009a0370` | `__aulldiv` | import thunk / CRT / external stub |
| `0x009a03e0` | `__aullrem` | import thunk / CRT / external stub |

## Inventory status breakdown

Python `Counter` on `status` fields in `inventory.jsonl`:

| Status | Count | % of listed |
|--------|------:|------------:|
| `full` | **17156** | 66.85% |
| `trivial-batch` | **8508** | 33.15% |
| `reviewed` | **0** | 0% |
| `none` / other | **0** | 0% |
| **Listed total** | **25664** | 100% |

### What inventory `trivial-batch` actually is

Among inventory rows with `status == "trivial-batch"`:

| Name class | Count |
|------------|------:|
| `Unwind@*` | **7837** |
| `Catch@*` | **671** |
| Import-ledger addr | **0** |
| Other | **0** |
| **Total** | **8508** |

Cross-check:

- All **8508** unwind-ledger addrs are present in inventory as `trivial-batch`.
- **0** `Unwind@` / `Catch@` inventory rows remain non-trivial.
- All **9** import-ledger addrs are present in inventory but stamped **`full`**, not `trivial-batch`.

### Why imports stay `full` in inventory

`coverage/stamp_inventory_status.py` order:

1. Name `Unwind@` / `Catch@` → `trivial-batch`
2. Addr in trivial ledgers **and** not in `have` (function record / raw) → `trivial-batch`
3. Addr in `have` → **`full`** (wins over import ledger)

The 9 import-ledger symbols already have artifacts under `functions/` / `raw/`, so stamping classifies them as `full`. That is **inventory code preference**, not proof they are dual-reviewed game managers. Durable import accounting remains the side ledger (`trivial_batch_imports.jsonl`), per `TRIVIAL_BATCH.md`.

### Full-status composition (context, not reclassification)

| Class | Count | Meaning |
|-------|------:|---------|
| `FUN_*` with `full` | **16466** | Bulk plate / record stamp — **not** dual depth |
| Named non-`FUN_*` with `full` | **690** | Includes managers, renames, **and** some thunk/import names still `full` |

**Honesty:** inventory `full` = accounted plate/artifact class for the listed row. It is **not** dual A/B depth and **not** bit-for-bit vs retail. See `WAVE_2026-07-29_wave3_coverage_honesty.md`.

## `progress.json` drift (do not trust stale fields)

Live file `coverage/progress.json` (updated field `2026-07-28`) vs this audit:

| Field | `progress.json` | This audit (Python) |
|-------|----------------:|--------------------:|
| `inventory_status.full` | 17156 | **17156** (match) |
| `inventory_status.trivial-batch` | 8508 | **8508** (match) |
| `trivial_batch_count` | **8565** | **8508** unwind only; **8508+9=8517** if counting both ledgers |
| `trivial_batch_imports_count` | **57** | **9** actual import JSONL rows |
| `full_coverage` | `true` | Means **inventory-listed accounted only** |
| Ghidra `function_count_ghidra` | 26256 | same reference |
| Inventory listed | 25664 | **25664** |
| Ghidra − listed gap | (implied) | **592** unlisted |

Likely historical confusion: there are **~57** inventory names matching `thunk_*` / `*Thunk*` still stamped `full` (56 `thunk_FUN_*` + 1 adjustor-style name). That is **not** the same as `trivial_batch_imports.jsonl` row count (**9**).

## Coverage criterion snapshot

| Criterion piece | State |
|-----------------|--------|
| Listed inventory rows terminal (`full` / `reviewed` / `trivial-batch`) | **Yes** — 25664/25664 |
| Every Ghidra function (26256) listed + terminal | **No** — **592** gap still unlisted |
| Deep dual for every terminal row | **No** — dual depth ≪ 26256 |
| Trivial-batch only used for Unwind/Catch in inventory | **Yes** (this pass) |
| Import ledger complete for all pure IAT/CRT stubs | **No** — only 9 rows; many name-similar units remain `full` |

## Do not invent trivial statuses for non-thunks

Hard rules for any future trivial-batch expansion:

1. **Never** stamp `trivial-batch` on game/domain names solely to reduce `full` counts (`CVOG*`, `Client*`, `Skill*`, `Vehicle*`, `Mission*`, combat/mission/inventory managers, etc.).
2. **Never** stamp bulk `FUN_*` as trivial without **body evidence** that the unit is a pure JMP thunk, adjustor, or compiler helper (name alone is insufficient for anonymous `FUN_*`).
3. **Do not** treat inventory `full` plates as candidates for downgrade without a verified thunk/compiler class.
4. Side ledgers are for **compiler / runtime / pure import / pure local thunk** classes only (see `TRIVIAL_BATCH.md` + `COVERAGE_LEDGER.md` status `trivial-batch`).
5. Prefer **name + body** (single JMP / JMP [IAT] / SEH helper pattern) over prefix lists alone. Prefix lists in `mark_import_thunks_trivial.py` are **hints**, not automatic truth.

## Name-heuristic residual still stamped `full` (candidates only)

**Not stamped this pass.** Counts are inventory `status=full` rows matching **strict name filters** for *possible* next trivial-batch research. Body verification required before any ledger write.

| Strict name class | Count (status=`full`) | Example |
|-------------------|----------------------:|---------|
| `thunk_FUN_*` local thunk names | **56** | `0x0040f970 thunk_FUN_0040f980` |
| Named adjustor-style `*_Thunk*` | **1** | `0x0053cd20 CVOGCharacter_CreateFromPacket_Thunk0xC0` |
| `D3DX*` | **23** | `D3DXVec3Normalize` |
| `__*` MSVC/CRT | **18** | includes the 9 import-ledger addrs |
| `nci*` | **13** | codec/API-looking stubs |
| `ov_*` | **8** | vorbis-looking imports |
| `operator_*` | **6** | `operator_new` / `operator_delete` |
| `WSA*` | **5** | `WSAStartup` etc. |
| libc-ish (`memmove`/`free`/`fopen`/…) | **~12** | scattered |
| Other CRT (`_snprintf`, `_atexit`, …) | **~7** | underscore CRT |
| **Sum of strict filters** | **~150** | **upper bound of name-only interest**, not approved batch size |

**Excluded from trivial recommendation without further proof:** all remaining named managers and all generic `FUN_*` plates.

## Suggested next batch criteria (more trivial-batch)

Ordered for safety and yield. Each batch should write/append a **dedicated JSONL ledger** and only then optionally restamp inventory.

### Batch A — Import / CRT / WinAPI pure stubs (expand imports ledger)

**Include when all hold:**

- Name matches known external/CRT/API class (`__*`, `D3DX*`, `Direct3D*`, `WSA*`, `ov_*`, libc names, `operator_new`/`delete`, obvious IAT symbols), **and**
- Decompiler/disasm is **JMP-to-IAT / external stub only** (no local game branches, no CVOG/client state), **and**
- Not already dual-owned as a domain manager.

**Exclude:** anything with non-trivial local logic; anything already under high-priority systems worklists for semantic reasons.

**Expected order of magnitude:** O(10²) at most among current listed inventory; actual accept set likely **≪ 150** after body filter.

**Ledger:** extend `trivial_batch_imports.jsonl` (or split `trivial_batch_crt.jsonl` if preferred) with `{addr,name,status,reason}`.

### Batch B — Local `thunk_FUN_*` / adjustor thunks

**Include when all hold:**

- Ghidra name is `thunk_FUN_*` **or** documented adjustor thunk (`*Thunk0xNN` style), **and**
- Body is pure forwarder (JMP / ADD ECX,imm + JMP), **and**
- Target is already inventoried (or target is separately accounted).

**Exclude:** “thunk” in a **comment or inferred manager name** without thunk body; multi-block wrappers that do real work.

**Expected order of magnitude:** **~57** name hits; accept only body-confirmed subset.

**Ledger:** new `trivial_batch_local_thunks.jsonl` (keep separate from SEH unwind and import ledgers).

### Batch C — Inventory gap export (592 unlisted Ghidra functions)

Before inventing more trivial classes inside the listed 25664:

1. Re-export / page-merge any functions present in Ghidra but missing from `inventory.jsonl` (gap **26256 − 25664 = 592**).
2. On new rows, auto-classify only **`Unwind@` / `Catch@`** into the unwind ledger (same rule as existing 8508).
3. Apply Batch A/B filters only after names exist in inventory.

This may add genuine trivial rows **without** touching game-logic plates.

### Batch D — Do **not** schedule as trivial-batch

- Bulk `FUN_*` plates already `full` (16466) — keep as reconstruction/rename depth, not trivial.
- Domain-named units (`CVOG*`, `Client*`, `Skill*`, …).
- Units under dual-review partitions for missions / skills / inventory / input.
- Any “looks small” heuristic without SEH/import/thunk body class.

## Recommended operator sequence (future work; not executed here)

1. Export missing 592 (Batch C) → merge inventory pages.
2. Body-scan Batch B `thunk_FUN_*` (small, high precision).
3. Body-scan Batch A external/CRT names; append import ledger only for accepts.
4. Run `stamp_inventory_status.py` only after ledger writes; document that existing artifacts force `full` over trivial unless stamp policy is deliberately changed.
5. Refresh `progress.json` so `trivial_batch_imports_count` and `trivial_batch_count` match live JSONL line counts (fix 57/8565 drift).
6. Leave dual-depth honesty unchanged: trivial-batch growth must not be narrated as dual-review progress.

## Refresh recipe

```powershell
# From repo root
python -c "from pathlib import Path; import json; from collections import Counter
cov=Path('docs/reconstruction/coverage')
for n in ['trivial_batch_unwind.jsonl','trivial_batch_imports.jsonl','inventory.jsonl']:
 p=cov/n; print(n, sum(1 for l in p.read_text(encoding='utf-8').splitlines() if l.strip()))
rows=[json.loads(l) for l in (cov/'inventory.jsonl').read_text(encoding='utf-8').splitlines() if l.strip()]
print('status', Counter(r.get('status') for r in rows))
print('tb name', Counter(('Unwind' if (r.get('name') or '').startswith('Unwind@') else 'Catch' if (r.get('name') or '').startswith('Catch@') else 'other') for r in rows if r.get('status')=='trivial-batch'))"
```

## Related

- Policy: `docs/reconstruction/coverage/TRIVIAL_BATCH.md`
- Stamp tool: `docs/reconstruction/coverage/stamp_inventory_status.py`
- Import marker: `docs/reconstruction/coverage/mark_import_thunks_trivial.py`
- Ledger overview: `docs/reconstruction/COVERAGE_LEDGER.md`
- Honesty companion: `docs/reconstruction/reviews/WAVE_2026-07-29_wave3_coverage_honesty.md`
- Machine stamp: `docs/reconstruction/coverage/progress.json`, `inventory.jsonl`
