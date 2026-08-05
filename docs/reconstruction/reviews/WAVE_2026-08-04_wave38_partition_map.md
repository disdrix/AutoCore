# Multi-agent partition map — wave 38 (2026-08-04)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **2128** unique A∩B |
| Rule | **One write owner per VA** |
| Tooling | `decompile_function` + `read_memory` (+ analyze/callers/xrefs); no `disassemble_bytes`; no Launcher |
| Priority rationale | Undualed callees of dualed managers / wave37 units / HP paths |

## Ownership

| Agent | VAs |
|-------|-----|
| W38-A | `0x0043d570`, `0x0043e750` |
| W38-B | `0x00457cc0`, `0x0096a630` |
| W38-C | `0x00970910`, `0x004363b0` |
| W38-D | `0x00436f10`, `0x00437000` |
| W38-E | `0x004372a0`, `0x004373b0` |
| W38-F | `0x00437e40`, `0x00437f70` |
| W38-G | `0x00438040`, `0x004382c0` |
| W38-H | `0x00456780`, `0x0074ce60` |
| W38-I | `0x00767570`, `0x00768760` |
| W38-J | `0x00769660`, `0x0076a200` |
| W38-K | `0x0096b930`, `0x004a8100` |
| W38-L | `0x004c17b0`, `0x00438140` |
| W38-M | `0x004129f0`, `0x00463e30` |
| W38-N | `0x00469f10`, `0x00754a10` |
| W38-O | `0x0043d770`, `0x0096e9f0` |
| W38-P | `0x0096efd0`, `0x00970060` |
| W38-Q | `0x00752370`, `0x0073e1e0` |
| W38-R | `0x0073eb40`, `0x00465d70` |
| W38-S | `0x005c6720`, `0x004cd8f0` |
| W38-T | `0x0074e310`, `0x0040ead0` |
| W38-U | `0x0043b800`, `0x0073be50` |
| W38-V | `0x0073d870`, `0x0073d8d0` |
| W38-W | `0x0073e980`, `0x0074f090` |
| W38-X | `0x0074f0c0`, `0x0075e710` |
| W38-Y | `0x0076c130`, `0x00966630` |
| W38-Z | `0x00966760`, `0x00968680` |
| W38-AA | `0x009686e0`, `0x00968720` |
| W38-AB | `0x0096c8e0`, `0x0096e8e0` |
| W38-AC | `0x00985580`, `0x00985610` |
| W38-AD | `0x00985f40`, `0x009864e0` |
| W38-AE | `0x00986570`, `0x00744ea0` |
| W38-AF | `0x00965600`, `0x004a05c0` |
| W38-AG | `0x00722790` |

## Deliverables per owned VA

1. Live `decompile_function` + `read_memory` (no `disassemble_bytes`).
2. Confirm/update trio raw + annotated + reconstructed-exact + function record.
3. Dual `reviews/A_aa_<va>_*.md` + `reviews/B_aa_<va>_*.md` with evidence, confirmations, residual gaps.
4. No parent ledger edits.
5. No invented product names without evidence; `_Inferred` when unproven.
6. Report: `docs/agents/task-dual-ab-<va1>[-<va2>]-w38X-report.md`.

## Verdict language

**accept** / **accept-with-gaps** / **reject**. Never claim runtime/diff Confirmed without Launcher. Terminal coverage remains **false**.
