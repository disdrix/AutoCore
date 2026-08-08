# ADV-WQ9L independent adversarial spot-check — dual-sealed WQ-009 depth-9 sample

| Field | Value |
|---|---|
| **Agent** | **ADV-WQ9L** (independent adversarial verifier — **not** dual author) |
| **Date** | `2026-08-05` |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | WQ-009 depth-9 residual duals (WQ9L-A / E / H2 / I sample) |
| **Scope** | Six dual-sealed units (STL + UI) — try to **falsify** dual A/B claims |
| **Tools** | Ghidra MCP `batch_decompile`, `read_memory`; dual A/B + raw + clean + function-record read-through |
| **Forbidden** | Parent ledgers; dual A/B rewrite; Launcher; inventing product names; `disassemble_bytes` |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** (no dual claim forced re-queue) |

---

## Sample units

| # | VA | Canonical name | Family |
|---|---|---|---|
| 1 | `0x00404000` | `StdTree_IteratorIncrement_Isnil131` | STL tree |
| 2 | `0x00408ad0` | `StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred` | STL tree |
| 3 | `0x007a8580` | `CNDUIWindow_ClearOwnedObject_Inferred` | UI |
| 4 | `0x00424060` | `ObjectCsList_DestroyAll_Inferred` | UI / object list |
| 5 | `0x0083a860` | `ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred` | UI shopveh |
| 6 | `0x0082ce20` | `CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred` | UI menu |

---

## Inspected evidence (all six)

| Kind | Paths |
|---|---|
| Dual A/B | `docs/reconstruction/reviews/A_aa_*` + `B_aa_*` for each VA above |
| Raw | `docs/reconstruction/raw/aa_<va>_FUN_*.md` (+ annotated twins) |
| Function records | `docs/reconstruction/functions/aa_<va>_*.md` |
| Clean | `docs/reconstruction/reconstructed-exact/<Canonical>.cpp` (+ `FUN_*` twins) |
| Live | `batch_decompile` of all six + callees `0x0083a7d0`, `0x0083ac90`, `0x007a85e0`, `0x0082d540` |
| Bytes | `read_memory` full/entry/epilogue samples + product strings |

---

## Summary table

| VA | Canonical | Dual verdict | **ADV** | Why |
|---|---|---|---|---|
| `0x00404000` | `StdTree_IteratorIncrement_Isnil131` | accept | **PASS** | isnil@+0x131 / EDX it / plain RET / successor CF sealed |
| `0x00408ad0` | `StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred` | accept-with-gaps | **PASS** | RET 0xC / string@+0x0C / size-- epilogue sealed; gaps honest |
| `0x007a8580` | `CNDUIWindow_ClearOwnedObject_Inferred` | accept-with-gaps | **PASS** | ECX this / +0x298 clear / flags=0 vs 1 / not complete dtor |
| `0x00424060` | `ObjectCsList_DestroyAll_Inferred` | accept | **PASS** | CS drain / NoNode4 / DestroyAll string / not list free |
| `0x0083a860` | `ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred` | accept-with-gaps | **PASS** | EAX host / EBX list_i / AL bool / +0x508 gate / 27 B |
| `0x0082ce20` | `CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred` | accept-with-gaps | **PASS** | +0x534 hash teardown / soft assert / not complete dtor |

**Score: 6/6 PASS. 0 FAIL. Terminal false.**

---

## Unit 1 — `0x00404000` StdTree_IteratorIncrement_Isnil131

### Dual claims under attack

| # | Attack | Result |
|---|---|---|
| 1 | Predecessor / `operator--` polarity | **Survives dual** — live decompile: right(+8) → left-min, else climb while **right**-child = **successor** |
| 2 | isnil at +0x31 / +0x19 / +0x29 / +0x49 | **Survives** — every guard `*(char*)(n+0x131)`; full body hex has only `80 xx 31 01 00 00` |
| 3 | Iterator in **ECX** (Isnil49 twin) | **Survives** — entry `8B 02` = `MOV EAX,[EDX]`; decompiler phantom ECX unused |
| 4 | Returns next node in EAX / non-void | **Survives** — only `*it` stores; dual exits plain `C3` |
| 5 | Body size / range wrong | **Survives** — live 88 B hex ends `…8902c3` at `0x00404057` |

### Live seal

```text
read_memory 0x00404000 len=88:
8b0280b83101000000754c8b480880b93101000000751b8b0180b83101000000750d
8bc88b0180b8310100000074f3890ac38b400480b8310100000075178bff8b0a3b48
08750e89028b400480b8310100000074eb8902c3
```

Live decompile ≡ dual clean CF (nil early-out; right non-nil → leftmost; parent climb; store `*it`).

| Claim | Conf |
|---|---|
| ABI EDX=`node**`; void; plain RET | **High** |
| isnil every branch `+0x131` | **High** |
| Leaf (no callees) | **High** |
| Not erase / not merge with `00408ad0` | **High** |

### Residual risks

- Product key/value English per multi-caller host maps (naming only).
- Runtime / bit-exact / differential open (not claimed Confirmed).

### ADV verdict

**PASS** — keep dual **accept**. No re-queue.

---

## Unit 2 — `0x00408ad0` StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred

### Dual claims under attack

| # | Attack | Result |
|---|---|---|
| 1 | Decompiler noreturn on `operator_delete` is full body | **Survives dual** — epilogue bytes past delete: `83 C4 54 C2 0C 00` (**RET 0xC**) |
| 2 | isnil31 family (+0x31 / no string dtor) | **Survives** — isnil `+0x131` / color `+0x130` / `~basic_string` @ node+0x0C |
| 3 | ECX-thiscall primary | **Survives** — 3 stack args; `RET 0x0C` |
| 4 | Range / free-subtree body | **Survives** — single-node erase; range is caller `FUN_00407b70` |
| 5 | Merge with succ peer `00404000` | **Survives** — this **calls** succ; different ABI |
| 6 | Two-child mid blocks truly unreachable | **Survives dual honesty** — dual flags decomp "unreachable" as **false**; clean documents simplified plate as **gap** |

### Live seal

```text
read_memory 0x00408e10:
… 64 89 0d 00 00 00 00  83 c4 54  c2 0c 00  cc cc
   FS:[0] restore        ADD ESP,0x54  RET 0xC
```

String plate at `0x00a152f0`: `"invalid map/set<T> iterator"` — confirmed via `read_memory`.

Live decompile CF matches dual stages (throw → `FUN_00404000` succ → unlink → RB recolor/rotate → `~string` → delete). Decompiler still truncates epilogue (false noreturn) — dual already seals this via bytes.

| Claim | Conf |
|---|---|
| RET 0xC / 3 stack args | **High** |
| isnil@+0x131 / color@+0x130 / string@+0x0C | **High** |
| size-- + `*outIt` in epilogue | **High** (bytes) |
| Two-child successor-swap plate exactness in **clean** | **Med** (documented gap) |
| Product map English | Open → `_Inferred` correct |

### Residual risks

- Clean two-child splice is simplified vs full MSVC erase (dual Med gap — ports must not trust simplified plate alone).
- Rotate/min/max peers `00403cb0` / `00403d00` / `00404160` / `004043c0` residual.
- Runtime / bit-exact open.

### ADV verdict

**PASS** — keep dual **accept-with-gaps**. Gaps are real but **disclosed**; no false sealed claim found. No re-queue.

---

## Unit 3 — `0x007a8580` CNDUIWindow_ClearOwnedObject_Inferred

### Dual claims under attack

| # | Attack | Result |
|---|---|---|
| 1 | Complete dtor of CNDUIWindow | **Survives** — no vtbl reinstall / no free `this`; parent complete is `0x007b5be0` |
| 2 | Always scalar-delete object @ +0x298 | **Survives** — delete only when ownership byte `+0xBC` set; else abandon-null |
| 3 | Child @ +0x2B4 always freed | **Survives** — flags=**0** (dtor without free) |
| 4 | cdecl / stack this | **Survives** — entry `8B F1` (`MOV ESI,ECX`); bare `C3` |
| 5 | Set pair is same function | **Survives** — live `FUN_007a85e0` distinct: vcall `+0x44` (this clear) then store |

### Live seal

```text
read_memory 0x007a8580 len=96:
53 56 8B F1 33 DB 39 9E 98 02 00 00 …   ; CMP [ESI+0x298]
… 8B 8E B4 02 00 00 … 53 FF 10 …       ; child +0x2B4 flags=0
… FF 52 4C … FF 90 88 02 00 00 …       ; vtbl+0x4C / +0x288
… 38 9E BC 00 00 00 … 6A 01 FF 12 …    ; +0xBC → delete flags=1
… 89 9E 98 02 00 00 5E 5B C3           ; always null +0x298; RET
```

`DAT_00a1419b` first byte `0x00` (empty C-string) — confirmed.

Set pair live decompile: `(**(code **)(*param_1 + 0x44))()` then `param_1[0xa6]=param_2` — clear @ vtbl **+0x44** sealed.

| Claim | Conf |
|---|---|
| ECX this / bare RET / 96 B | **High** |
| Offsets +0x298 / +0x2B4 / +0xBC | **High** |
| flags=0 child vs flags=1 owned | **High** |
| Product English of owned type @ +0x298 | Open → `_Inferred` correct |

### Residual risks

- Product type behind +0x298 and vtbl +0x4C / +0x288 method English open.
- Runtime open.

### ADV verdict

**PASS** — keep dual **accept-with-gaps**. No re-queue.

---

## Unit 4 — `0x00424060` ObjectCsList_DestroyAll_Inferred

### Dual claims under attack

| # | Attack | Result |
|---|---|---|
| 1 | Merge with ClearDestroy `0x0051b8a0` (zeros node+4) | **Survives** — live loop has no store to `node+4`; NoNode4 twin of `0x0051bc90` |
| 2 | List complete dtor / frees list | **Survives** — no `operator_delete(this)` / no `DeleteCriticalSection` |
| 3 | Next pointer at node+0x10 | **Survives** — decompile `puVar1[2]` / +8 |
| 4 | Product "DestroyAll" invent | **Survives** — string @ `0x00a33af0`: `"List Error!  DestroyAll Call Stack:\n%s\n"` |
| 5 | stdcall free function | **Survives** — `8B F1`; bare RET |

### Live seal

```text
read_memory 0x00424060 entry:
55 8B EC 6A FF 68 90 D7 9B 00 … B8 04 10 00 00 E8 …  ; SEH + chkstk 0x1004
… 8B F1 89 65 F0 8D 7E 04 …                           ; ESI=this; EDI=this+4 CS
```

Live decompile: `EnterCriticalSection(this+4)` → busy `+0x28` throw `0x80070005` → drain head `+0x1C` next@+8 dtor(1) → zero +0x24/+0x20/+0x1C → `LeaveCS`.

| Claim | Conf |
|---|---|
| ECX list* / bare RET / SEH | **High** |
| Drain under CS; NoNode4 | **High** |
| Product method English DestroyAll | **High** |
| Family demangle `ObjectCsList` vs UI `CNDDoubleList` | Med (kept `_Inferred`) |

### Residual risks

- Shared base demangle breadth across 22+ callers (UI nest is CNDDoubleList TextMarkup; name stays structural `_Inferred`).
- Runtime open.

### ADV verdict

**PASS** — keep dual **accept**. No re-queue.

---

## Unit 5 — `0x0083a860` ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred

### Dual claims under attack

| # | Attack | Result |
|---|---|---|
| 1 | thiscall ECX=host | **Survives** — no ECX host use; `PUSH EAX` → finder |
| 2 | EAX = list_i | **Survives** — EAX is host; list_i is **EBX** |
| 3 | Returns slot pointer | **Survives** — `SETNZ AL` / `XOR AL,AL`; bool only |
| 4 | Mutator / full reindex | **Survives** — 27 B pure probe; parent `0083ac90` owns reindex |
| 5 | Id base not 0x9ca4 | **Survives** — finder live: `GetId()-0x9ca4 == EBX` |

### Live seal

```text
read_memory 0x0083a860:
50 E8 6A FF FF FF 85 C0 74 0E 33 C9 39 88 08 05 00 00
0F 95 C1 8A C1 C3 32 C0 C3  CC×5
; PUSH EAX / CALL 0083a7d0 / TEST / JZ miss /
; CMP [EAX+0x508],ECX / SETNZ / RET / XOR AL,AL / RET
```

Sole call site bytes @ `0x0083adbe`:

```text
8B DF          ; MOV EBX, EDI   (list_i)
8B C5          ; MOV EAX, EBP   (host)
E8 99 FA FF FF ; CALL 0083a860
84 C0          ; TEST AL, AL
75 0C          ; JNZ soft path
```

Finder `0x0083a7d0` live decompile: scan `host+0x50c[5]`, `unaff_EBX` compare, `RET 4` — confirms EBX list_i contract used by this unit.

| Claim | Conf |
|---|---|
| EAX host / EBX list_i / AL bool / bare RET | **High** |
| +0x508 bound-obj gate | **High** |
| Sole CALL from `0083ac90` id-match | **High** |
| Shopveh product English | Med (parent dual + scaffold; `_Inferred`) |
| Finder dual | Open residual |

### Residual risks

- `FUN_0083a7d0` undualed (WQ residual chain).
- Clean `FUN_0083a860` twin is a **register-ABI plate stub** (`return 0`) — portable named form is the authority; do not call twin as product.
- Type behind +0x508 structural only.
- Runtime open.

### ADV verdict

**PASS** — keep dual **accept-with-gaps**. No re-queue.

---

## Unit 6 — `0x0082ce20` CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred

### Dual claims under attack

| # | Attack | Result |
|---|---|---|
| 1 | Full CVOGMenu complete dtor | **Survives** — parent `0x0082d540` installs vtbl, calls this, then `CNDUIDialog_CompleteDtor` `0x00792c20` |
| 2 | Hard-abort on TraversalLock errors | **Survives** — soft `FUN_007a4480` logs then continues / forces lock |
| 3 | Frees CVOGMenu `this` | **Survives** — bare RET; nulls hash slot only |
| 4 | Nested list helpers take entry* not entry+8 | **Survives** — dual + clean: list shell at entry+8; decompile `iVar1+8` |
| 5 | Hash slot abstract index only | **Survives as +0x534** — entry `8B B5 34 05 00 00` = `MOV ESI,[EBP+0x534]` |
| 6 | Merge with `StdList_Clear_ESI` `0x00415e90` | **Survives** — different ABI/role (dialog list clear) |

### Live seal

```text
read_memory 0x0082ce20 entry:
83 EC 08 53 55 8B E9 56 8B B5 34 05 00 00 33 DB …
; SUB ESP,8; MOV EBP,ECX; MOV ESI,[EBP+0x534]; XOR EBX,EBX

read_memory 0x0082cf20 epilogue:
… 5E 5D 5B 83 C4 08 C3  CC…
; POP ESI/EBP/EBX; ADD ESP,8; RET
```

Parent complete live: `*this = PTR_FUN_00a72f6c; FUN_0082ce20(); FUN_00792c20();` — role as **member hash teardown only** sealed.

Live decompile walk: TraversalLock@hash+0x1d → ordered next@+0x14 / entry@+8 → nested list lock → iterate + vcall menu **+0xbc** → unlock → destroy chain → scalar-delete hash flags=1 → null +0x534.

| Claim | Conf |
|---|---|
| ECX this / +0x534 / bare RET after SUB ESP,8 | **High** |
| Soft asserts only | **High** |
| Notify then destroy side-effect order | **High** |
| Scalar-delete hash (not recreate) | **High** |
| Product hash stamp / vtbl[+0xbc] English | Open → `_Inferred` correct |
| `FUN_004113b0` full thiscall formal plate | Med (decompiler elides ECX; dual documents repair) |

### Residual risks

- Product RTTI/stamp of object at +0x534; notify method English; nested list element type destroyed by `FUN_00410d60`.
- Iterate helper ABI fully dual-sealed only as callee residual.
- Runtime open.

### ADV verdict

**PASS** — keep dual **accept-with-gaps**. No re-queue.

---

## Cross-sample notes (ADV)

1. **STL pair coherence:** `00404000` (succ, plain RET, EDX) is correctly a **callee** of `00408ad0` (erase, RET 0xC, 3 stack args) — duals do not merge them.
2. **UI dtor-helper pattern:** `007a8580`, `00424060`, and `0082ce20` are all correctly sealed as **helpers / partial teardowns**, not complete/scalar host dtors — live parents still chain further work.
3. **Register-ABI micro-helper:** `0083a860` is the highest ABI-risk unit in the sample; live call-site + finder `unaff_EBX` independently confirm EAX/EBX/AL contract.
4. **Honest gaps preserved:** units with `_Inferred` duals did not over-promote product English; two-child erase plate Med gap remains the largest port risk (not a dual-lie).

---

## Final

| Metric | Value |
|---|---|
| Sampled | 6 |
| **PASS** | **6** |
| **FAIL** | **0** |
| Recommend re-queue | none |
| Terminal false | **yes** |

**Output only:** `docs/reconstruction/reviews/ADV_wq9l_spotcheck.md` (this file). Dual A/B files **not** modified.
