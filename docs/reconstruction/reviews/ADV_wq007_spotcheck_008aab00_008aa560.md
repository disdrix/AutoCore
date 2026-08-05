# Independent adversarial spot-check — WQ7R-C duals `0x008aab00` + `0x008aa560`

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** WQ7R-C dual author) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | WQ7R-C OWN pair (mission dialog chrome helpers) |
| **Units** | `0x008aab00` `MissionDialog_ParseMarkupToRichText_Inferred`; `0x008aa560` `MissionDialog_ClearResponseButtonSlots_Inferred` |
| **Report under test** | `docs/agents/task-dual-ab-008aab00-008aa560-wq7rc-report.md` |
| **Tools** | Ghidra MCP `batch_decompile`, `read_memory`, `get_function_by_address`, `get_function_xrefs` / `get_xrefs_to`, `get_assembly_context` |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite |
| **Image** | `autoassault.exe` base `0x400000` |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-008aab00-008aa560-wq7rc-report.md` |
| `docs/reconstruction/reviews/A_aa_008aab00_MissionDialog_ParseMarkupToRichText_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_008aab00_MissionDialog_ParseMarkupToRichText_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_008aa560_MissionDialog_ClearResponseButtonSlots_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_008aa560_MissionDialog_ClearResponseButtonSlots_Inferred.md` |

### Artifacts (on disk)

| Kind | `aa_008aab00` | `aa_008aa560` |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_008aab00_FUN_008aab00.md` | `…/aa_008aa560_FUN_008aa560.md` |
| Annotated | present | present |
| Clean twin | `reconstructed-exact/FUN_008aab00.cpp` | `…/FUN_008aa560.cpp` |
| Function named | present | present |
| Scratch | `tmp/a_008aab00.md` | `tmp/a_008aa560.md` |

### Live Ghidra (this session)

| Check | Result |
|---|---|
| `batch_decompile(0x008aab00, 0x008aa560)` | Live ≡ dual matrix / clear loop; decompiler labels noted below |
| `get_function_by_address` | `FUN_008aab00` body `008aab00`–`008aaf58`; `FUN_008aa560` body `008aa560`–`008aa5a6` |
| `read_memory` @ `0x008aab00` (32 B) | `B8 4C 20 00 00` + chkstk; `8B F1` (markup←ECX); null tests on stack widget / ESI |
| `read_memory` @ `0x008aaf48` (24 B) | final AppendText call; epilogue `5F 5E 5D 81 C4 4C 20 00 00 C3`; pad `CC` |
| `read_memory` color/pause region | ARGB immediates + `PUSH 0x14` + vtbl `+0x230`/`+0x23c`/`+0x250`/`+0x254` |
| `read_memory` @ `0x008aa560` (80 B) | full 70 B body + `CC` pad; hex ≡ dual report append |
| `read_memory` @ `DAT_00d1bbf5` (64 B) | all static zeros (runtime-filled claim holds) |
| `get_function_xrefs` / `get_xrefs_to` `0x008aab00` | **6** sites: `008aaf60`, `008a3510`×2, `008cc5a0`, `008cdae0`, `008dbe10` |
| `get_function_xrefs` `0x008aa560` | **1** site: `FUN_008ac110` @ `0x008ac138` |
| `get_assembly_context` callers | stack-arg + `ADD ESP,4` (or combined cleanup) for markup; `MOV EBX,EDI` then clear |

---

## Unit A — `0x008aab00` markup → richtext

### Confirmations (sealed claims hold)

| Claim | Independent result | Conf |
|---|---|---|
| Body `0x008aab00`–`0x008aaf58` excl. (**1112 B** / `0x458`) | Ghidra bounds match; pad `CC` after epilogue | **High** |
| Frame `0x204c` + `__chkstk` | Entry `B8 4C 20 00 00`; epilogue `81 C4 4C 20 00 00` | **High** |
| **ECX = markup C-string** (not widget this) | Entry `8B F1`; callers LEA/MOV string into ECX | **High** |
| **Stack = richtext widget***; callers clean **4** | Entry loads stack formal into EBP; sites `ADD ESP,4` (or paired cleanup) after CALL | **High** |
| Null-guard both args | `TEST EBP` / `TEST ESI` early exits | **High** |
| Tag matrix imp/npc/inst/loc/emote + closes + pause + key | Live decompile strnicmp ladder complete | **High** |
| Colors ARGB exact | Live PUSH immediates (see table) | **High** |
| `[$pause]` → **vtbl+0x254(0x14)** | Bytes `6A 14` + `FF 92 54 02 00 00` | **High** |
| Plain / key display → **vtbl+0x250** | Decomp + epilogue region `FF 92 50 02 00 00` | **High** |
| Color open **+0x230** / close **+0x23c** | Bytes `FF 92 30 02 00 00` / `FF 90 3C 02 00 00` | **High** |
| Key table stride **0x34**, end **0x00d1d455**, **120** slots | `(0xd1d455−0xd1bbf5)/0x34 = 120` exact; static image zeros | **High** |
| Free Look special + `FUN_007f5120` / `FUN_007f9160` / sprintf | Live decomp CF; non-zero `007f9160` skips sprintf | **High** CF |
| Classification worker / multi-caller (6) | 6 unconditional xrefs; no packet/journal stores | **High** |
| Name `_Inferred`; reject `Named_npc` product | Scaffold-only plates correctly demoted | **High** |
| Dual A/B **accept-with-gaps** | Justified: product English + key helpers open | **High** |

### Color immediates (live PUSH, LE dword)

| Tag | Dual claim | Live bytes | Verdict |
|---|---|---|---|
| `[$imp]` | `0xFFFF2D00` | `68 00 2D FF FF` | **Confirmed** |
| `[$npc]` | `0xFF256EC8` | `68 C8 6E 25 FF` | **Confirmed** |
| `[$inst]` | `0xFFC5C025` | `68 25 C0 C5 FF` | **Confirmed** |
| `[$loc]` | `0xFFF59623` | `68 23 96 F5 FF` | **Confirmed** |
| `[$emote]` | `0xFF29B525` | `68 25 B5 29 FF` | **Confirmed** |

### Adversarial attacks (this pass)

| # | Attack | Result |
|---|---|---|
| 1 | Decompiler `__thiscall` means ECX is widget | **Falsified** — ECX is markup string; widget is stack formal |
| 2 | Function mutates mission journal / sends packets | **Falsified** — paint-only (widget vtbl + locals) |
| 3 | Sole caller / journal-only | **Falsified** — 6 xrefs across detail/header/help UI |
| 4 | Colors RGB without alpha | **Falsified** — all immediates `0xFFxxxxxx` |
| 5 | Pause length invented | **Falsified** — imm `0x14` in bytes |
| 6 | Key table static content in image | **Survives open** — `DAT_00d1bbf5` all zero static |
| 7 | Unknown `[$` sequences are hard errors | **Falsified** — unknown emits first char as plain |
| 8 | Clean invented control flow | **No invention found** vs live decompile |

### Nits (non-blocking)

| Nit | Detail |
|---|---|
| Review A §5.2 address | Claims epilogue start `@0x008aaf50` as `5F 5E 5D…`; live has **`5F` at `0x008aaf4f`**, `5E` at `0x008aaf50`. Sequence itself correct. |
| Ghidra exclusive body vs RET | Exclusive end `0x008aaf58` is the address of **`C3` RET** itself; size `0x458` matches Ghidra's reported span and dual claim. Pad `CC` begins at `0x008aaf59`. Documented consistently with Ghidra; not a semantic error. |
| Work buffer split | Decompiler splits `local_1000`/`local_ffa` (~4K); frame `0x204c` seals total staging. Dual already notes this. |

### Gaps (still open — agree with dual)

1. Product/PDB English.  
2. Product names for vtbl `+0x230` / `+0x23c` / `+0x250` / `+0x254`.  
3. Runtime fill of `DAT_00d1bbf5`.  
4. Nested dual of `FUN_007f5120` / `FUN_007f9160` (WQ7R-G).  
5. Runtime / bit-exact / differential.

### Unit A verdict

**Uphold dual: accept-with-gaps.** Markup matrix, ABI, colors, paint ordinals, body frame, and multi-caller role independently re-sealed. No material break. Product English and key-display helpers remain open.

---

## Unit B — `0x008aa560` clear response button slots

### Confirmations (sealed claims hold)

| Claim | Independent result | Conf |
|---|---|---|
| Body `0x008aa560`–`0x008aa5a6` excl. (**70 B** / `0x46`) | Live full hex; pad `CC…` after `C3` | **High** |
| Full body hex ≡ dual report | Byte-identical to sealed dump | **High** |
| **EBX = dialog host*** | Caller `@0x008ac136` `MOV EBX,EDI`; LEAs use EBX | **High** |
| No stack args; plain **`RET`** | Ends `5F 5E 5D C3` (not `C2 xx`) | **High** |
| Fixed **8** iterations | `BD 08 00 00 00` (`mov ebp,8`); no load of `+0x510` | **High** |
| TFID bank **`dialog+0x518`**, stride 8 | `8D BB 18 05 00 00`; stores `−1`/`−1`; `83 C7 08` | **High** |
| Widget bank **`dialog+0x708`**, stride 4 | `8D B3 08 07 00 00`; `83 C6 04` | **High** |
| Destroy via host **vtbl+0xBC** | `50 8B CB FF 92 BC 00 00 00` (push widget; ECX=host; call) | **High** role |
| Zero pointer after destroy | `C7 06 00 00 00 00` | **High** |
| Decompiler `+0x1c2` / `+0x146` dword indices | `0x1c2*4=0x708`; `0x146*4=0x518` | **High** |
| Sole caller `FUN_008ac110` pre-rebuild | 1 xref; context immediately before column clamp / rebuild loop on `+0x510` | **High** |
| Not reward chrome / not markup | Offsets only +0x518/+0x708; no tags | **High** |
| Dual A/B **accept-with-gaps** | Product English + TFID pair English open | **High** |

### Live full body hex (pad excluded)

```
5556578db3080700008dbb18050000bd080000008b0685c0c707ffffffff
c74704ffffffff74118b13508bcbff92bc000000c7060000000083c708
83c60483ed0175d15f5e5dc3
```

≡ dual report append; ≡ Review A sealed table.

### Caller framing (live)

```text
008ac128  CMP [EDI+0x4C0], 0      ; chrome gate
008ac12f  JZ  exit
008ac135  PUSH EBX
008ac136  MOV EBX, EDI            ; EBX = dialog this
008ac138  CALL 0x008aa560         ; clear 8 slots
008ac13d  CMP [EDI+0x640], 0      ; columns
…
008ac150  XOR EBX, EBX
008ac152  CMP [EDI+0x510], EBX    ; rebuild count (after clear)
```

**Ordering seal:** clear always runs before rebuild; clear itself does **not** gate on `+0x510` (hardcoded 8). Dual port note correct.

### Adversarial attacks (this pass)

| # | Attack | Result |
|---|---|---|
| 1 | `unaff_EBX` is decompiler junk | **Falsified** — deliberate ABI; caller sets EBX |
| 2 | Loop count from `dialog+0x510` | **Falsified** — imm 8 only |
| 3 | Function rebuilds / allocates buttons | **Falsified** — clear/destroy only |
| 4 | Clears reward banks (+0x698 family) | **Falsified** — only +0x518 / +0x708 |
| 5 | vtbl+0xBC is AppendText (+0x250) | **Falsified** — different ordinal; free/detach pattern |
| 6 | Multiple callers | **Falsified** — sole xref `008ac110` |
| 7 | Stack formals / RET n | **Falsified** — bare `C3` |
| 8 | Scaffold callee-of-xml plate is product English | **Demote** — alias only (dual agrees) |

### Gaps (still open — agree with dual)

1. Product/PDB name.  
2. Product name for vtbl+0xBC (destroy vs detach vs release).  
3. Exact TFID pair field English (mission-key / response-id / COID) — external HandleButton consumers.  
4. Runtime / bit-exact / differential.

### Unit B verdict

**Uphold dual: accept-with-gaps.** 8-slot clear, EBX ABI, offsets, destroy ordinal, and sole pre-rebuild caller independently re-sealed. No material break.

---

## Cross-unit / package checks

| Check | Result |
|---|---|
| Units orthogonal | Markup painter ≠ slot clear; dual correctly separates |
| Pairing with `FUN_008ac110` | Clear is pre-step of rebuild; not conflated with markup |
| Port notes | Markup: lexer + ARGB + paint ordinals; Clear: always wipe 8, no `+0x510` gate — both match live |
| A/B internal consistency | A (fidelity) and B (adversarial) agree accept-with-gaps; residual attacks match open gaps |
| Twin CF vs live | `FUN_008aab00.cpp` / `FUN_008aa560.cpp` track live decompile; no invented branches found |
| Forbidden tools | Dual claims no `disassemble_bytes`; this ADV used only decompile + `read_memory` + xrefs/context |

---

## Package verdict

| Unit | Dual verdict | ADV result |
|---|---|---|
| `0x008aab00` | accept-with-gaps | **Uphold** — sealed facts reconfirmed; gaps still open |
| `0x008aa560` | accept-with-gaps | **Uphold** — sealed facts reconfirmed; gaps still open |
| Dual report overall | WQ7R-C complete for OWN pair | **Accept package** |

### Material findings

**None.** No falsified sealed claims. Only documentation nits (epilogue address off-by-one in Review A §5.2 for markup unit).

### Residual risk (not dual failures)

- Port of keybind display still depends on WQ7R-G (`007f5120` / `007f9160`).  
- Widget vtbl product names remain ordinal-only.  
- TFID pair semantics require HandleButton / consumer duals.  
- No runtime Confirmed for either unit.

---

## Deliverable

- `docs/reconstruction/reviews/ADV_wq007_spotcheck_008aab00_008aa560.md` (this file)
)
