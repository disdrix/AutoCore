# Independent adversarial spot-check — WQ7R-A duals `0x008ac7a0` + `0x008aaf60`

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** WQ7R-A dual author) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | WQ7R-A OWN pair — multi-active tip + mission dialog header caption |
| **Work item** | **WQ-007** missions-progression residual seal |
| **Tools** | Ghidra MCP `batch_decompile` / `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_callers`, `get_function_xrefs`, `get_function_callees`; artifact read-through (report + A/B + raw + clean + function records) |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite |
| **Image** | `autoassault.exe` base `0x400000` |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-008ac7a0-008aaf60-wq7ra-report.md` |
| `docs/reconstruction/reviews/A_aa_008ac7a0_Client_MaybeShowMultiActiveMissionTip_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_008ac7a0_Client_MaybeShowMultiActiveMissionTip_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_008aaf60_Client_MissionDialog_SetHeaderCaption_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_008aaf60_Client_MissionDialog_SetHeaderCaption_Inferred.md` |

### Artifacts

| Kind | `aa_008ac7a0` | `aa_008aaf60` |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_008ac7a0_FUN_008ac7a0.md` | `docs/reconstruction/raw/aa_008aaf60_FUN_008aaf60.md` |
| Annotated | `…/aa_008ac7a0_FUN_008ac7a0.annotated.md` | `…/aa_008aaf60_FUN_008aaf60.annotated.md` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008ac7a0.cpp` | `…/FUN_008aaf60.cpp` |
| Clean named | `…/Client_MaybeShowMultiActiveMissionTip_Inferred.cpp` | `…/Client_MissionDialog_SetHeaderCaption_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_008ac7a0_FUN_008ac7a0.md` | `…/aa_008aaf60_FUN_008aaf60.md` |
| Function named | `…/aa_008ac7a0_Client_MaybeShowMultiActiveMissionTip_Inferred.md` | `…/aa_008aaf60_Client_MissionDialog_SetHeaderCaption_Inferred.md` |

### Live Ghidra spot-checks

| Check | Result |
|---|---|
| `batch_decompile(0x008ac7a0, 0x008aaf60)` | Live CF ≡ raw WQ7R-A scaffold for both units |
| `get_function_by_address(0x008ac7a0)` | Body `008ac7a0`–`008ac884` → **228 B / 0xE4** (matches dual) |
| `get_function_by_address(0x008aaf60)` | Body `008aaf60`–`008ab098` → **312 B / 0x138** (matches dual) |
| `read_memory 0x008ac7a0` len 240 | Full body hex ≡ raw WQ7R-A append; epilogue `cmp ebx,2` / `jl` / `push 0x20` / `mov ecx,00d1a840` / tip call / `pop ecx` / plain `C3`; pad `CC` |
| `read_memory 0x008aaf60` len 320 | Full body hex ≡ raw WQ7R-A append; both branches `6a 01 6a 01 6a 00` + `call [vtbl+0x1d8]`; common tail `push 0` / `call [vtbl+0x214]` / `call FUN_008aa610` / `add esp,0x28` / `C3` |
| `get_function_callers(0x008ac7a0)` | Sole `Client_MissionDialogHandleButton` |
| `get_function_xrefs(0x008ac7a0)` | 1 UNCONDITIONAL_CALL @ `0x008aec20` |
| `get_function_callers(0x008aaf60)` | `Client_ShowNpcMissionDialogUI`, `Client_UpdateMissionJournal` (named parents; see xrefs for full site count) |
| `get_function_xrefs(0x008aaf60)` | **6** UNCONDITIONAL_CALL: ShowNpc×3 (`00943a9d`/`00943af1`/`00943b27`), UpdateJournal×2 (`008ae1ec`/`008ae21b`), `0093e661` |
| `get_function_by_address(0x0093e450)` | Body `0093e450`–`0093e7cc` **contains** site `0093e661` |
| `read_memory 0x0093e65c` | `mov ecx,ebx; call rel → 0x008aaf60` (EDI pre-set nearby) |
| `get_function_callees(0x008ac7a0)` | `Client_MaybeShowFirstTimeTip`, `FUN_007a4480` only |
| `get_function_callees(0x008aaf60)` | `005465c0`, `007a69d0`, `007a6de0`, `008aa610`, `008aab00`, std::string ctor/dtor |

---

## Byte-level ABI / CF re-verify

### `0x008ac7a0` (multi-active tip)

Decoded from live `read_memory` (no disassembly tool):

| Fact | Byte evidence | Dual claim |
|---|---|---|
| Load singleton | `a1 d8 b6 d1 00` → `mov eax, [DAT_00d1b6d8]` | **OK** |
| Null gate | `85 c0` / `0f 84 …` | **OK** |
| Gate byte `+0xd34` bit0 | `8a 88 34 0d 00 00` / `80 e1 01` / `0f 85 …` (skip if set) | **OK** |
| Hash root `+0x540` | `8b b8 40 05 00 00` / later `8b ba 40 05 00 00` | **OK** |
| Count / node zero | `33 db` / `33 f6` | **OK** |
| Lock `hash+0x1d` | `80 7f 1d 00` / `c6 47 1d 01` / unlock `c6 41 1d 00` | **OK** |
| Chain `+0x14` / payload `+8` | `8b 76 14` / `8b 77 14` / `8b 46 08` | **OK** |
| Count predicate | `66 83 b8 f8 00 00 00 00` (`word +0xf8 == 0`); `83 b8 fc 00 00 00 ff` (`dword +0xfc != -1`); `83 c3 01` | **OK** |
| Threshold ≥ 2 | `83 fb 02` / `7c 0c` (`cmp ebx,2` / `jl skip`) | **OK** — ≡ decompile `1 < count` |
| Tip id `0x20` + this `DAT_00d1a840` | `6a 20` / `b9 40 a8 d1 00` / call tip / `59` | **OK** (decompiler omits this; bytes win) |
| Epilogue | plain `c3` | **OK** — no-arg void |
| No list / C2S callees | callees = tip + HashError log only | **OK** |

### `0x008aaf60` (header caption)

| Fact | Byte evidence | Dual claim |
|---|---|---|
| SEH frame | `64 a1 00…` / `68 b7 bc 9a 00` (`LAB_009abcb7`) / `64 89 25…` | **OK** |
| ECX = dialog | `56 8b f1` → `push esi; mov esi, ecx` | **OK** |
| Widget `+0x6e0` null gate | `83 be e0 06 00 00 00` / `0f 84 01 01 00 00` | **OK** |
| EDI caption key | `85 ff` / `0f 84 c2 00 00 00` (clear branch); non-zero `6a ff 57` into `007a6de0` | **OK** (decompiler `unaff_EDI`) |
| Clear path `+0x1d8(0,1,1)` | `6a 01 6a 01 6a 00 ff 90 d8 01 00 00` | **OK** — three stack args; decompile lag `(0)` |
| Clear path `+0x34c` | `ff 92 4c 03 00 00` | **OK** |
| Set path resolve | `call 007a69d0`; `push -1; push edi; call 007a6de0`; std::string ctor | **OK** |
| Optional format | `a1 d8 b6 d1 00` / `jz` skip / `push &string; push char; call 005465c0; add esp,8` | **OK** |
| Set path `+0x1d8(0,1,1)` | same `6a 01 6a 01 6a 00 ff 92 d8 01 00 00` | **OK** |
| `FUN_008aab00(widget)` | `push [esi+0x6e0]; call 008aab00` | **OK** (order sealed; body residual) |
| Layout `+0x1f0` / `+0x34c` | `ff 92 f0 01 00 00` / `ff 90 4c 03 00 00` | **OK** |
| Cond show | `cmp byte [DAT_00d1b21c],0` / `je show`; `cmp state(+0x648),2` / `je`; `cmp ,3` / `jne skip`; `call [vtbl+0x1fc]` | **OK** |
| Common `+0x214(0)` | `6a 00 ff 90 14 02 00 00` | **OK** |
| Common `FUN_008aa610` | `e8 87 f5 ff ff` → `008aa610` | **OK** (body residual WQ7R-B) |
| Epilogue | `add esp, 0x28` / plain `c3` | **OK** |

---

## Confirmed claims

### `0x008ac7a0` (`aa_008ac7a0` / `Client_MaybeShowMultiActiveMissionTip_Inferred`)

| Claim | Verdict |
|---|---|
| Body `008ac7a0`–`008ac884`, 228 B | **Confirmed** |
| Live decompile ≡ raw CF | **Confirmed** |
| No-arg plain `ret` (`C3`); void | **Confirmed** |
| Gate: `DAT_00d1b6d8 != 0` and `(+0xd34)&1 == 0` | **Confirmed** |
| Active-mission hash at singleton `+0x540`; lock `hash+0x1d` | **Confirmed** |
| Walk `+0x14` chain; payload `node+8` | **Confirmed** |
| Count iff `short(+0xf8)==0 && int(+0xfc)!=-1` | **Confirmed** |
| Tip only when count ≥ 2 | **Confirmed** |
| Tip id `0x20`, this `DAT_00d1a840` | **Confirmed** (bytes; decompile omits this) |
| Sole caller accept path `Client_MissionDialogHandleButton` @ `0x008aec20` | **Confirmed** |
| Not list rebuild / not C2S / not GiveMission | **Confirmed** (callees + CF) |
| Scaffold `Named_VOG_DEBUG_STOP` not product role | **Confirmed** (string is lock assert only) |
| Product tip/field English open; gate≡FirstFlags Probable only | **Fair residual** |
| Runtime / bit-exact open; `terminal_coverage=false` | **Fair residual** |
| Dual A **accept-with-gaps** + B **accept-with-gaps** | **Appropriate** |

### `0x008aaf60` (`aa_008aaf60` / `Client_MissionDialog_SetHeaderCaption_Inferred`)

| Claim | Verdict |
|---|---|
| Body `008aaf60`–`008ab098`, 312 B | **Confirmed** |
| Live decompile ≡ raw CF (statement order); bytes win on arity | **Confirmed** |
| ECX = dialog; EDI = caption key (0 clear); plain `C3` | **Confirmed** |
| Null widget `+0x6e0` → no-op | **Confirmed** |
| Clear: `+0x1d8(0,1,1)` then `+0x34c` | **Confirmed** |
| Set order: resolve → optional `005465c0` → `+0x1d8(0,1,1)` → `008aab00` → `+0x1f0` → `+0x34c` → cond `+0x1fc` | **Confirmed** |
| Cond show: `DAT_00d1b21c==0` OR state `+0x648` ∈ {2,3} | **Confirmed** |
| Common tail `+0x214(0)` + `FUN_008aa610` | **Confirmed** |
| Decompiler lag on `+0x1d8` single-arg vs three-arg | **Confirmed** — dual correctly privileges bytes |
| Six xrefs: ShowNpc×3, UpdateJournal×2, `FUN_0093e450`@`0093e661` | **Confirmed** |
| Nested `005465c0` / `008aab00` / `008aa610` order only (not dualed here) | **Confirmed** / fair OWN scope |
| Product widget/vtable English open; EDI key domain open | **Fair residual** |
| Runtime / bit-exact open; `terminal_coverage=false` | **Fair residual** |
| Dual A **accept-with-gaps** + B **accept-with-gaps** | **Appropriate** |

---

## Soft nits (non-blocking)

1. **Tip thiscall decompiler lag (`008ac7a0`)** — Live decompile prints `Client_MaybeShowFirstTimeTip(0x20)` without the `DAT_00d1a840` this. Dual A/B/raw/clean all seal `mov ecx, 0x00d1a840` from bytes. No dual failure; port must use thiscall host.

2. **`007a6de0` arity decompiler lag (`008aaf60`)** — Decompile shows bare `FUN_007a6de0()`; bytes push **EDI** and **−1**. Dual documents register formal + push order. Clean named unit matches.

3. **`get_function_callers` vs xrefs for `008aaf60`** — Callers API returned two named parents (ShowNpc, UpdateJournal); sixth site is inside `FUN_0093e450` and is visible via xrefs + body containment check. Dual’s “6 callers/xrefs” is correct when read as **call sites**, not distinct parent-name rows from the callers helper alone.

4. **Clean twin shape** — `FUN_008aaf60.cpp` intentionally keeps decompiler `__fastcall` + `unaff_EDI` shape; named clean carries the register contract. Acceptable dual hygiene.

5. **Nested callee ABI** — `FUN_008aa610` is residual WQ7R-B (ESI-oriented per that dual). This unit only seals the call site; no overclaim found in WQ7R-A sealed text.

---

## Residual gaps (honest; duals already flag most)

1. Product / PDB names for both functions and the header widget class.  
2. Tip `0x20` string-table English.  
3. Payload type + product names for `+0xf8` / `+0xfc` (multi-active qualifier).  
4. Independent proof that gate `+0xd34` bit0 ≡ tip-0x20 FirstFlags on the same object as `MaybeShowFirstTimeTip`’s map (dual correctly leaves **Probable**).  
5. EDI caption-key domain (id vs pointer beyond `007a6de0` consumption).  
6. Vtable English for slots `+0x1d8` / `+0x1f0` / `+0x1fc` / `+0x214` / `+0x34c`.  
7. Product meaning of `DAT_00d1b21c`.  
8. Nested residual dual bodies (`005465c0`, `008aab00`, `008aa610`) — sibling OWN, not this pair.  
9. Runtime / bit-exact / differential (`terminal_coverage=false`; no Launcher).  

No sealed CF/ABI claim was falsified by this spot-check.

---

## Dual quality verdict (not bare LGTM)

### `aa_008ac7a0` — **PASS** (`accept-with-gaps` stands)

A/B roles are clean (fidelity checklist vs attack table). Independent re-verify seals:

- no-arg `C3` void ABI  
- singleton gate + `+0xd34` bit0  
- `+0x540` hash walk / lock / payload predicate  
- count ≥ 2 → tip `0x20` on `DAT_00d1a840`  
- sole accept-path caller; no list/C2S side effects  

B correctly falsifies parent “refresh dialog lists” commentary and scaffold `VOG_DEBUG_STOP` naming. Residual gaps are product English / FirstFlags identity / runtime only. Artifact chain (raw + WQ7R-A append, A/B, clean named+twin, function records) coheres with live Ghidra.

### `aa_008aaf60` — **PASS** (`accept-with-gaps` stands)

Strengths:

- ECX/EDI register contract sealed against decompiler `unaff_EDI`.  
- Three-arg `+0x1d8(0,1,1)` sealed both branches (bytes over decompiler).  
- Clear vs set CF, cond show, common tail sealed.  
- Six call sites re-confirmed (including `FUN_0093e450` @ `0093e661`).  
- Nested residual OWN boundaries explicit; call order only.  

Defect-class notes: none on owned VA CF/ABI. Soft decompiler-lag documentation is already present in dual text and is accurate.

### Pair / process quality

| Dimension | Assessment |
|---|---|
| Dual A+B present for both VAs | Yes |
| Co-owned tip + header pair under WQ-007 mission dialog residual | Sound (accept path tip vs dialog chrome header) |
| Port hygiene (not list rebuild; not full journal; three-arg `+0x1d8`) | Sound |
| Bytes-over-decompiler discipline | Sound |
| Terminal coverage honesty | Sound (`false`) |
| OWN-ONLY hygiene / no ledger edits claimed | Outside this verifier’s rewrite scope |
| Spot-check vs Ghidra live | Both units seal; soft nits only |

---

## Summary

| VA | Dual quality | Verdict retention | Action |
|----|--------------|-------------------|--------|
| `0x008ac7a0` | **PASS** | keep **accept-with-gaps** | none required |
| `0x008aaf60` | **PASS** | keep **accept-with-gaps** | none required |

**ADV artifact written:**

- `docs/reconstruction/reviews/ADV_wq007_spotcheck_008ac7a0_008aaf60.md` (this file)
