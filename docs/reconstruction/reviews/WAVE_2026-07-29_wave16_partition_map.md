# Multi-agent partition map — wave 16 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1227** unique A∩B |
| Rule | **One write owner per VA** — OWN-ONLY dual seal |
| Tooling | `decompile_function` + `read_memory`; avoid `disassemble_bytes`; no Launcher |

## High-priority residual (explicit NEED)

| Agent | VAs | Focus |
|-------|-----|-------|
| W16-A | `0x0056c860`, `0x0056e000` | combat/heat residual |
| W16-B | `0x0058d980`, `0x004e2f70` | combat impulse / loot residual |
| W16-C | `0x005e0480`, `0x005e0590` | loot catalog residual |
| W16-D | `0x005e1860`, `0x00519a30` | catalog / equip residual |
| W16-E | `0x004d32c0`, `0x00404730` | equip / skill-DB residual |
| W16-F | `0x0041c7e0`, `0x004205e0` | skill DB helpers |

## Nested callee residual (high xref from dualed units)

| Agent | VAs | Focus |
|-------|-----|-------|
| W16-G | `0x0040dbf0`, `0x005ae2b0` | nested callee (high mention) |
| W16-H | `0x00723ab0`, `0x00436340` | nested callee |
| W16-I | `0x004e3260`, `0x005cd3b0` | nested callee |
| W16-J | `0x00437cd0`, `0x0041d7b0` | nested callee / skill-DB adj |
| W16-K | `0x004a0b90`, `0x00767160` | nested callee |
| W16-L | `0x00403450`, `0x0071ffc0` | nested callee |
| W16-M | `0x00490070`, `0x0060d460` | nested callee |
| W16-N | `0x00419b40`, `0x00720a40` | nested callee |
| W16-O | `0x005121d0`, `0x004d5c10` | nested callee |
| W16-P | `0x007181c0`, `0x0046e280` | nested callee |
| W16-Q | `0x0067ba30`, `0x0067b110` | nested callee |
| W16-R | `0x0076c330`, `0x005304a0` | nested callee |
| W16-S | `0x00404670`, `0x00410490` | nested callee |
| W16-T | `0x00436190`, `0x004a4fa0` | nested callee |

## Agent deliverables (per owned VA)

1. Live Ghidra `decompile_function` @ VA + `read_memory` for constants/bytes (no `disassemble_bytes` default).
2. Confirm/update trio: `raw/aa_*`, `raw/aa_*.annotated.md`, `reconstructed-exact/*.cpp`, `functions/aa_*.md` if thin.
3. Dual reviews: `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md` (fidelity + adversarial), verdict accept / accept-with-gaps / reject.
4. Structural names only unless product string/RTTI proves otherwise.
5. **Do not** edit: `WORK_QUEUE.md`, `RESUME.md`, `ACTIVE_WORK.md`, `CHANGE_LOG.md`, `COVERAGE_LEDGER.md`, `coverage/progress.json`, `inventory.jsonl`, this partition map (except own dual files under `reviews/`).

## Parent merge (after agents return)

- Count unique A∩B duals
- Restamp RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress
- Run experiments suite → scratch
- Terminal remains **false** until every live VA meets standard
