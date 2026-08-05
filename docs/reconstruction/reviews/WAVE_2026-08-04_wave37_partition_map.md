# Multi-agent partition map — wave 37 (2026-08-04)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **2065** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; no Launcher |
| Priority rationale | Nested callees of already-dualed high-priority / high-mention manager paths; includes wave36 residual W36-K |

## Ownership (2 VAs each)

| Agent | VAs |
|-------|-----|
| W37-A | `0x0098fd80`, `0x0098df00` |
| W37-B | `0x00971480`, `0x00685b40` |
| W37-C | `0x00469c80`, `0x004a04f0` |
| W37-D | `0x005b2ba0`, `0x00972cc0` |
| W37-E | `0x007669d0`, `0x00431b30` |
| W37-F | `0x005b3520`, `0x004c0fe0` |
| W37-G | `0x004c1800`, `0x004bcae0` |
| W37-H | `0x0096f0e0`, `0x0096f510` |
| W37-I | `0x00968a50`, `0x0099c1c0` |
| W37-J | `0x004e2bd0`, `0x0055ca90` |
| W37-K | `0x00458510`, `0x005e13b0` |
| W37-L | `0x005b3fa0`, `0x0075bf40` |
| W37-M | `0x0043d5e0`, `0x005b3420` |
| W37-N | `0x00735390`, `0x0075eff0` |
| W37-O | `0x00788db0`, `0x0051d0c0` |
| W37-P | `0x0045dd60`, `0x0052ade0` |
| W37-Q | `0x009701d0`, `0x0043bd40` |
| W37-R | `0x007a26c0`, `0x0044b440` |
| W37-S | `0x00765740`, `0x0076b080` |
| W37-T | `0x00410420`, `0x004bfd10` |
| W37-U | `0x00730b50`, `0x004bc580` |
| W37-V | `0x00746400`, `0x00996d70` |
| W37-W | `0x004a7ff0`, `0x00970cf0` |
| W37-X | `0x0073d940`, `0x0071a9d0` |
| W37-Y | `0x00461e60`, `0x009847c0` |
| W37-Z | `0x0044a380`, `0x0076bc00` |
| W37-AA | `0x0055c250`, `0x005e0610` |
| W37-AB | `0x0096e4b0`, `0x005d4fd0` |
| W37-AC | `0x0068a620`, `0x005b8340` |
| W37-AD | `0x00970fc0`, `0x004982d0` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md` with inspected evidence, confirmations, residual gaps (not bare LGTM).
4. No parent ledger edits (WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress.json).
5. No invented product names without string/RTTI/xref evidence; use `_Inferred` when English is not Confirmed.
6. Avoid bare `undefined4` as the sole clean type surface when better types are evidenced.
7. Report: `docs/agents/task-dual-ab-<va1>-<va2>-w37X-report.md` (lowercase letter suffix matching agent).

## Verdict language

Use **accept** / **accept-with-gaps** / **reject**. Never claim runtime/diff/bit-exact Confirmed without Launcher evidence. Mark terminal coverage false always in agent reports.
