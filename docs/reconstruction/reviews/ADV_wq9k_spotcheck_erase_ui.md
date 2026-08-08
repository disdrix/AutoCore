# Independent adversarial spot-check — WQ9K erase-range (isnil131/isnil2d) + UI complete dtors

| Field | Value |
|---|---|
| **Date** | `2026-08-05` |
| **Role** | Independent adversarial verifier (**not** dual author WQ9K-B / WQ9K-F / WQ9K-G) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | `WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-B** (`00407b70`/`00407f90`); **WQ9K-F** (`0078ca80`); **WQ9K-G** (`00792c20`) |
| **Units** | (1) `0x00407b70` `StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred`; (2) `0x00407f90` `StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred`; (3) `0x0078ca80` `CNDUIWndBuffered_CompleteDtor`; (4) `0x00792c20` `CNDUIDialog_CompleteDtor` |
| **Tools** | Dual reports A/B + raw/annotated/clean + dual agent reports + VERIFICATION_MATRIX line-proof (WQ-007) |
| **Live Ghidra this session** | Not required for seal audit — claims re-checked against dual-published raw decompile + re-verify body/ABI plates + clean CF rewrite |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** |
| **Overall verdict** | **PASS-WITH-FINDINGS** |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-00407b70-00407f90-wq9kb-report.md` |
| `docs/agents/task-dual-ab-0078ca80-007b5be0-wq9kf-report.md` |
| `docs/agents/task-dual-ab-0082d540-00792c20-wq9kg-report.md` |
| `docs/reconstruction/reviews/A_aa_00407b70_StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00407b70_StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_00407f90_StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00407f90_StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0078ca80_CNDUIWndBuffered_CompleteDtor.md` |
| `docs/reconstruction/reviews/B_aa_0078ca80_CNDUIWndBuffered_CompleteDtor.md` |
| `docs/reconstruction/reviews/A_aa_00792c20_CNDUIDialog_CompleteDtor.md` |
| `docs/reconstruction/reviews/B_aa_00792c20_CNDUIDialog_CompleteDtor.md` |

### Artifacts (four units)

| Kind | `00407b70` | `00407f90` | `0078ca80` | `00792c20` |
|---|---|---|---|---|
| Raw (+ re-verify) | `raw/aa_00407b70_FUN_00407b70.md` | `raw/aa_00407f90_FUN_00407f90.md` | `raw/aa_0078ca80_FUN_0078ca80.md` | `raw/aa_00792c20_FUN_00792c20.md` |
| Annotated | `…FUN_00407b70.annotated.md` | `…FUN_00407f90.annotated.md` | `…FUN_0078ca80.annotated.md` | `…FUN_00792c20.annotated.md` |
| Clean named | `StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred.cpp` | `StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred.cpp` | `CNDUIWndBuffered_CompleteDtor.cpp` | `CNDUIDialog_CompleteDtor.cpp` |
| Clean twin | `FUN_00407b70.cpp` | `FUN_00407f90.cpp` | `FUN_0078ca80.cpp` | `FUN_00792c20.cpp` |
| Function named | `aa_00407b70_StdMap_…` | `aa_00407f90_StdMap_…` | `aa_0078ca80_CNDUIWndBuffered_…` | `aa_00792c20_CNDUIDialog_…` |

### Support / chain evidence (not OWN duals of this ADV set)

| Artifact | Use |
|---|---|
| Dual WQ9J-I free-subtree twins `00409920` / `00409970` | Full-clear callees of erase-range parents; DestroyStr0C family seal |
| Dual WQ9J-F StringKey erase `004094c0` | Partial-path erase for isnil2d range unit |
| Dual WQ9J-B CWndVehicle complete `00834520` | Derived caller of buffered complete `0078ca80` |
| Dual WQ9K-F peer `007b5be0` CNDUIWindow complete | Base of both UI units in this ADV set |
| Dual WQ9K-G peer `0082d540` CVOGMenu complete | Intermediate caller of CNDUIDialog complete |
| isnil29 peer `00407d70` Map_EraseRange_C | Negative twin (do not merge) |

### Evidence cross-check matrix

| Check | Result |
|---|---|
| Raw decompile ≡ dual A CF tables | **Yes** (all four; register-this / truncated-tail traps overridden by re-verify) |
| Dual re-verify body ends + ABI recorded | **Yes** (exclusive ends for erase pair; inclusive + hex for buffered; inclusive + tail hex for dialog) |
| Clean named owns correct VA (no plate collision) | **Yes** (all four; twins re-express / forward) |
| Body-size arithmetic | **Yes** (see unit sections) |
| isnil131 range ≠ isnil2d range (ESI/EDI, free, partial erase) | **Holds** — dual B merge attacks falsified |
| Complete dtor ≠ scalar (no free host); RTTI product names sealed on UI units | **Holds** |
| Dialog decompiler false-noreturn on member `operator_delete` corrected | **Holds** (tail hex + clean base chain) |
| Terminal honesty | **false** on all duals / cleans / this ADV |
| Runtime Confirmed | **Not claimed** |

---

## Unit 1 — `0x00407b70` StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred

### Body / ABI seal (independent)

```text
0x00407bea − 0x00407b70 = 0x7A = 122 B  (exclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x00407b70`–`0x00407bea` exclusive (**122 B** / `0x7A`); pad `CC`; next `0x00407bf0` | **Confirmed** (size math + raw re-verify) |
| **ESI = map\*** (register-this; not ECX thiscall); stack `(out, first, last)`; both exits **`RET 0x0c`**; EAX = out | **Confirmed** (raw unaff_ESI + re-verify plate) |
| Full clear: `first == *head && last == head` → free `00409920` + head L/P/R self-link + size@+8=0 | **Confirmed** (raw decomp ≡ dual A) |
| Partial: residual succ `00404000` then residual erase `00408ad0` (~string@+0x0c) | **Confirmed** (raw empty-arg decomp; re-verify call-site plate) |
| Family **isnil@+0x131** via free/succ/erase (no isnil imm in body) | **Confirmed** — dual B free-only / isnil2d-merge attacks falsified |
| Callers (2): `00405110` @ `0040513e`; `00405df0` @ `00405e00` | **Accepted** (raw re-verify) |
| Name `_Inferred` / product open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
// Machine: ESI=map*; stack out/first/last; RET 0x0c
undefined4 * FUN_00407b70(undefined4 *param_1, int *param_2, int *param_3)
{
  int *piVar1;
  int unaff_ESI; // map*

  piVar1 = *(int **)(unaff_ESI + 4); // head
  if ((param_2 == (int *)*piVar1) && (param_3 == piVar1)) {
    FUN_00409920(piVar1[1]); // FreeSubtree isnil131; ECX=map per bytes
    // head parent/left/right = head; size = 0
    *param_1 = **(undefined4 **)(unaff_ESI + 4);
    return param_1;
  }
  while (param_2 != param_3) {
    FUN_00404000(); // successor isnil131
    FUN_00408ad0(); // erase+rebalance isnil131
  }
  *param_1 = param_2;
  return param_1;
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x00407b70`** (122 B exclusive) |
| CF rewrite | **Match** — full clear free+reset; partial succ then erase; `*out`/return |
| ABI plate | Explicit **ESI** register-this + RET 0x0c; free twin `00409920` |
| Scaffold twin | `#include` of named clean — **OK** |
| Family hygiene | Comments reject merge with isnil2d / isnil29 peers — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — CF/ABI/free/partial High; product open |
| B adversarial | accept-with-gaps | **Agree** — free-only / ECX-thiscall / isnil29-merge / family-cross / RET4-or-8 falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**. Residual: product node English; undualed succ/erase `00404000`/`00408ad0`.

---

## Unit 2 — `0x00407f90` StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred

### Body / ABI seal (independent)

```text
0x00408042 − 0x00407f90 = 0xB2 = 178 B  (exclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x00407f90`–`0x00408042` exclusive (**178 B** / `0xB2`); pad `CC`; next SEH `0x00408050` | **Confirmed** |
| **EDI = map\*** (register-this; not ECX thiscall); stack `(out, first, last)`; both exits **`RET 0x0c`**; EAX = out | **Confirmed** (raw unaff_EDI + re-verify) |
| Full clear → free `00409970` + head reset + size 0 | **Confirmed** |
| Partial: **inlined** successor with **isnil@+0x2d** immediates then dualed StringKey erase `004094c0` | **Confirmed** (raw `+0x2d` walks; re-verify `80 7? 2d 00`) |
| Distinct from isnil131 peer (different this-reg, free, partial erase, layout) | **Holds** — dual B merge reject |
| Callers (2): `00404ec0` @ `00404eee`; `004061f0` @ `00406200` | **Accepted** |
| Name `_Inferred` / product open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
// Machine: EDI=map*; stack out/first/last; RET 0x0c
undefined4 * FUN_00407f90(undefined4 *param_1, int *param_2, int *param_3)
{
  int *piVar2;
  int unaff_EDI; // map*

  piVar2 = *(int **)(unaff_EDI + 4); // head
  if ((param_2 == (int *)*piVar2) && (param_3 == piVar2)) {
    FUN_00409970(piVar2[1]); // FreeSubtree isnil2d
    // head reset + size 0
    *param_1 = **(undefined4 **)(unaff_EDI + 4);
    return param_1;
  }
  while (param_2 != param_3) {
    // inlined successor using *(node+0x2d) isnil tests
    FUN_004094c0(); // StringKey erase+rebalance
  }
  *param_1 = param_2;
  return param_1;
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x00407f90`** (178 B exclusive) |
| CF rewrite | **Match** — full clear free+reset; extracted `tree_successor` (isnil@+0x2d); StringKey erase |
| ABI plate | Explicit **EDI** register-this + RET 0x0c |
| Scaffold twin | `#include` of named clean — **OK** |
| Partial loop | Captures successor then erase then `first = succ` — behavior-preserving plate (binary may also write outIt) |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — CF/ABI/isnil2d/free/StringKey erase High |
| B adversarial | accept-with-gaps | **Agree** — free-only / ECX-thiscall / isnil131-merge / Map_EraseNode_B-merge / RET4-or-8 falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**. Residual: product string-key map English only (partial erase already dualed).

---

## Unit 3 — `0x0078ca80` CNDUIWndBuffered_CompleteDtor

### Body / ABI seal (independent)

```text
0x0078caef − 0x0078ca80 + 1 = 0x70 = 112 B  (inclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x0078ca80`–`0x0078caef` inclusive (**112 B** / `0x70`); next ctor `0x0078caf0` | **Confirmed** (size math + full-body hex plate) |
| **`__thiscall`** ECX=this (`MOV ESI,ECX`); SEH `LAB_009b3fee`; epilogue `ADD ESP,0x10; RET` (`C3`); void | **Confirmed** (raw + hex ends `83c410c3`) |
| Installs vtbl **`PTR_FUN_00a99f74`** | **Confirmed** (`C7 06 74 9F A9 00`) |
| Helpers `FUN_007a8580` then `FUN_0078c3d0` | **Confirmed** |
| Nested `@+0x2A8` (`this[0xAA]`): if non-null `vtbl[0](1)`; **always** null field | **Confirmed** (raw + dual B always-null seal; hex `c786a802000000000000`) |
| Base `FUN_007b5be0` (CNDUIWindow complete) | **Confirmed** |
| Does **not** free host | **Confirmed** — free is scalar peer `004293f0` only |
| RTTI COL → **`.?AVCNDUIWndBuffered@@`** | **Confirmed** (dual re-verify COL chain) |
| Product name sealed (not `_Inferred`) | **Correct** |

### Live / raw decompile (independent summary)

```c
void __fastcall FUN_0078ca80(undefined4 *param_1 /*this*/)
{
  // SEH LAB_009b3fee; ESI=this
  *param_1 = &PTR_FUN_00a99f74;
  FUN_007a8580();
  FUN_0078c3d0();
  if ((undefined4 *)param_1[0xaa] != 0) { // +0x2A8
    (*(code *)**(undefined4 **)param_1[0xaa])(1);
  }
  param_1[0xaa] = 0; // always
  FUN_007b5be0(); // base CNDUIWindow complete
  return; // no operator_delete(this)
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x0078ca80`** (112 B) |
| CF rewrite | **Match** — vtbl, helpers, nested scalar-delete, always-null, base; no host free |
| Nested index | `self[0xAA]` ≡ +0x2A8 — **OK** |
| Scaffold twin | Forwards to named clean — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — complete CF/ABI/vtbl/RTTI/nested/base High |
| B adversarial | accept-with-gaps | **Agree** — scalar/vector/host-free/cdecl/wrong-class/merge-with-window attacks falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**. Residual: helper English `007a8580`/`0078c3d0`; nested HostBase product type.

---

## Unit 4 — `0x00792c20` CNDUIDialog_CompleteDtor

### Body / ABI seal (independent)

```text
0x00792d12 − 0x00792c20 + 1 = 0xF3 = 243 B  (inclusive true end)
Ghidra DB end 0x00792ceb is truncated (false noreturn)
```

| Claim | Independent result |
|---|---|
| True range `0x00792c20`–`0x00792d12` inclusive (**243 B** / `0xF3`); pad then ctor `0x00792d20` | **Confirmed** (size math + dual B body-end attack) |
| Ghidra scaffold decompile ends at member `operator_delete` with false noreturn | **Confirmed** — raw historical capture retains WARNING |
| **`__thiscall`** ECX=this; SEH `LAB_009b4054`; epilogue `ADD ESP,0x10; RET`; void | **Confirmed** (tail hex `83 c4 10 c3`) |
| Installs vtbl **`PTR_FUN_00a98f44`** | **Confirmed** (raw + re-verify) |
| Owned slots: scalar-delete `[0x130], [0x132]…[0x136]` ≡ `+0x4c0, +0x4c8…+0x4d8`; **skip `[0x131]`/`+0x4c4`** | **Confirmed** (raw dword-index pattern + dual B skip attack) |
| List clear `FUN_00415e90` at `this+0x4dc`; member free `operator_delete(+0x4e0)` **returns** then zero | **Confirmed** (tail hex: `CALL delete; ADD ESP,4; … CALL 007b5be0`) |
| Base `FUN_007b5be0` after EH=`-1` | **Confirmed** |
| Does **not** free host | **Confirmed** — free is scalar peer `004280d0` only |
| RTTI COL → **`.?AVCNDUIDialog@@`** | **Confirmed** |
| Product name sealed (prefer over prior ctor `NDUIContainerPanel_*`) | **Correct** |
| Hundreds of callers (shared NDUI dialog base) | **Accepted** (dual xref_count 304) |

### Live / raw decompile (independent summary)

```c
// Scaffold decompile TRUNCATES after member delete (false noreturn).
// Bytes-authoritative completion:
void __fastcall FUN_00792c20(undefined4 *param_1 /*this*/)
{
  // SEH LAB_009b4054
  *param_1 = &PTR_FUN_00a98f44; // CNDUIDialog vtbl
  FUN_007917c0();
  // null-safe vtbl[0](1) then zero on:
  //   [0x130], [0x132]..[0x136]  // skip [0x131] / +0x4c4
  FUN_00415e90(); // ESI = this+0x4dc
  operator_delete((void *)param_1[0x138]); // +0x4e0 MEMBER — returns
  // zero +0x4e0; EH = -1
  FUN_007b5be0(); // deeper window complete
  // ADD ESP,0x10; RET — no free this
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x00792c20`** (243 B true; documents Ghidra truncation) |
| CF rewrite | **Match** on vtbl, owned-slot map (skip +0x4c4), member free returns, base chain |
| `FUN_00415e90` | Clean uses `(void)0` plate stub with ESI comment — **honest residual**, not silent omit of role (see F4) |
| Scaffold twin | Forwards to named clean — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — ABI/offsets/RTTI/base chain High; decomp incomplete flagged |
| B adversarial | accept-with-gaps | **Agree** — scalar / host-noreturn / truncated-body / wrong-vtbl / free-all-six / leaf-no-base / merge-with-CVOGMenu falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**. Residual: slot English; undualed `007917c0`/`00415e90`/`007b5be0`; Ghidra body-end repair.

---

## Findings (non-blocking)

| # | Severity | Finding | Impact |
|---|---|---|---|
| F1 | Low (port) | **Erase-range ABI family trap:** isnil131 unit uses **ESI=map\***; isnil2d twin uses **EDI=map\***; both **`RET 0x0c`** (3 stack args). Neither is ECX `__thiscall`. Free callees still take **ECX=map**. | Port must preserve caller register-this convention; do not rewrite both as standard thiscall without call-site audit. |
| F2 | Low (port) | **Family cross-merge trap:** same role (range erase full-clear parent) but **not** layout-compatible — free `00409920` vs `00409970`; partial residual `00408ad0` vs dualed StringKey `004094c0`; isnil@+0x131 vs +0x2d. isnil29 peer `00407d70` is a third clone. | Keep three families distinct in AutoCore ports. |
| F3 | Info | **Dialog decomp false-noreturn:** scaffold raw ends at `operator_delete(+0x4e0)` with “does not return”; true body continues through zero + `FUN_007b5be0` + `ADD ESP,0x10; RET`. Dual B + tail hex seal correctly. | Never treat dual-published decompile alone as complete for this VA. |
| F4 | Info | **Clean plate stub:** `CNDUIDialog_CompleteDtor.cpp` documents `FUN_00415e90` with ESI=`this+0x4dc` but body is `(void)0` rather than a callable rewrite. Role sealed in dual/raw; executable clean incomplete for that leaf only. | Port must still invoke list-clear helper; not dual overclaim. |
| F5 | Info | **Matrix domain taxonomy:** VERIFICATION_MATRIX rows L319–320 / L327 / L330 tag all four under `skills-abilities` (WQ-009 residual path). Duals correctly classify as STL tree helpers + UI complete dtors. | Ledger taxonomy residual only. |
| F6 | Info | **Parent residual** (expected): isnil131 succ/erase `00404000`/`00408ad0`; buffered helpers `007a8580`/`0078c3d0`; dialog helpers `007917c0`/`00415e90`; deep base `007b5be0` dual residual on dialog path (dualed as OWN peer under WQ9K-F, still product English open). | Not dual overclaim. |
| F7 | Info | Product English open on erase pair (`_Inferred`); UI product RTTI sealed (`CNDUIWndBuffered` / `CNDUIDialog`); nested/owned layout English open. | Correct Terminal **false**. |

No CF reject. No dual A↔B contradiction on sealed ABI/role. No clean plate VA collision. No Terminal overclaim. No Runtime Confirmed claim.

---

## Overall unit scorecard

| Unit | Dual A | Dual B | ADV unit | Keep dual verdict? |
|---|---|---|---|---|
| `aa_00407b70` EraseRange isnil131 | accept-with-gaps | accept-with-gaps | **PASS** | Yes |
| `aa_00407f90` EraseRange isnil2d | accept-with-gaps | accept-with-gaps | **PASS** | Yes |
| `aa_0078ca80` CNDUIWndBuffered CompleteDtor | accept-with-gaps | accept-with-gaps | **PASS** | Yes |
| `aa_00792c20` CNDUIDialog CompleteDtor | accept-with-gaps | accept-with-gaps | **PASS** | Yes |

**Overall:** **PASS-WITH-FINDINGS** — dual seals stand; findings are port traps + expected residual + clean list-clear plate stub, not reject reasons.

---

## WQ-007 matrix re-confirm (line numbers)

Independent line-proof that the two requested WQ-007 residual units appear in `docs/reconstruction/VERIFICATION_MATRIX.md`:

| Stable ID | Canonical name | Main matrix row | Residual index row |
|---|---|---|---|
| `aa_00411180` | `StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred` | **L93** | **L397** (`present in Functions table`) |
| `aa_007f5120` | `Input_KeyCodeToDisplayName` | **L97** | **L399** (`present in Functions table`) |

Both sit under the WQ-007 residual dual block (main Functions table WQ-007 cluster L83–98; durable index section **L381–402**, header “WQ-007 residual dual index (16/16)”). Status remains **partial** with dual A/B sealed and runtime open — consistent with Terminal **false**.

---

## Process notes

- Independent ADV only; **not** dual author of WQ9K-B / WQ9K-F / WQ9K-G.
- Read dual A/B + agent reports + raw (+ re-verify appends) + named/twin cleans for all four units.
- **No** `disassemble_bytes`; **no** parent ledger edits; **no** dual rewrites; **no** Launcher.
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
