# Independent adversarial spot-check — WQ9J PodCopy/UninitCopy + vehicle/waypoint complete dtors

| Field | Value |
|---|---|
| **Date** | `2026-08-05` |
| **Role** | Independent adversarial verifier (**not** dual author WQ9J-A / WQ9J-B) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | `WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-A** units `00409f50`/`0040a520`; **WQ9J-B** units `00834520`/`00832fa0` |
| **Units** | (1) `0x00409f50` `StdVector_PodCopyElement_Elem12_Inferred`; (2) `0x0040a520` `StdVector_UninitializedCopy_Elem0x28_Inferred`; (3) `0x00834520` `CWndVehicle_CompleteDtor`; (4) `0x00832fa0` `CWndWaypointIcon_CompleteDtor` |
| **Tools** | Dual reports A/B + raw/annotated/clean + function records + dual agent reports + VERIFICATION_MATRIX line-proof (WQ-007) |
| **Live Ghidra this session** | Not required for seal audit — claims re-checked against dual-published raw decompile + re-verify body/ABI hex plates + clean CF rewrite |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite; Launcher |
| **Image** | `autoassault.exe` base `0x400000` |
| **Terminal** | **false** |
| **Overall verdict** | **PASS-WITH-FINDINGS** |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-00409f50-0040a520-wq9ja-report.md` |
| `docs/agents/task-dual-ab-00834520-00832fa0-wq9jb-report.md` |
| `docs/reconstruction/reviews/A_aa_00409f50_StdVector_PodCopyElement_Elem12_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_00409f50_StdVector_PodCopyElement_Elem12_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0040a520_StdVector_UninitializedCopy_Elem0x28_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0040a520_StdVector_UninitializedCopy_Elem0x28_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_00834520_CWndVehicle_CompleteDtor.md` |
| `docs/reconstruction/reviews/B_aa_00834520_CWndVehicle_CompleteDtor.md` |
| `docs/reconstruction/reviews/A_aa_00832fa0_CWndWaypointIcon_CompleteDtor.md` |
| `docs/reconstruction/reviews/B_aa_00832fa0_CWndWaypointIcon_CompleteDtor.md` |

### Artifacts (four units)

| Kind | `00409f50` | `0040a520` | `00834520` | `00832fa0` |
|---|---|---|---|---|
| Raw (+ re-verify) | `raw/aa_00409f50_FUN_00409f50.md` | `raw/aa_0040a520_FUN_0040a520.md` | `raw/aa_00834520_FUN_00834520.md` | `raw/aa_00832fa0_FUN_00832fa0.md` |
| Annotated | `…FUN_00409f50.annotated.md` | `…FUN_0040a520.annotated.md` | `…FUN_00834520.annotated.md` | `…FUN_00832fa0.annotated.md` |
| Clean named | `StdVector_PodCopyElement_Elem12_Inferred.cpp` | `StdVector_UninitializedCopy_Elem0x28_Inferred.cpp` | `CWndVehicle_CompleteDtor.cpp` | `CWndWaypointIcon_CompleteDtor.cpp` |
| Clean twin | `FUN_00409f50.cpp` | `FUN_0040a520.cpp` | `FUN_00834520.cpp` | `FUN_00832fa0.cpp` |
| Function named | `aa_00409f50_StdVector_…` | `aa_0040a520_StdVector_…` | `aa_00834520_CWndVehicle_…` | `aa_00832fa0_CWndWaypointIcon_…` |

### Support / chain evidence (not OWN duals of this ADV set)

| Artifact | Use |
|---|---|
| Dual WQ9I-A ConstructN Elem12 `00409db0` | Sole ConstructN parent of PodCopy leaf `00409f50` (loop + dest+=0x0C) |
| Dual WQ9I-B PodCopy 0x28 `00409f30` | Sole element leaf of UninitCopy `0040a520` (EAX/EDX / 10 dwords) |
| Prior ADV `ADV_wq9i_spotcheck_vector_list.md` | Flagged undualed Elem12 leaf + EAX/ECX vs EAX/EDX ABI trap |
| Dual WQ9I-F scalar `004160d0` | Sole caller of CWndVehicle complete |
| Dual WQ9I-H scalar `00416350` | Sole caller of CWndWaypointIcon complete |
| Raw `aa_0040a590` / `aa_00409ae0` / `aa_00408050` | Range twin / trampoline / InsertN residual consumers |

### Evidence cross-check matrix

| Check | Result |
|---|---|
| Raw decompile ≡ dual A CF tables | **Yes** (all four; decomp traps overridden by bytes where noted) |
| Dual re-verify body ends + entry/exit hex recorded | **Yes** (all four; PodCopy full 21 B plate; UninitCopy 101 B + listing; both UI full-body hex) |
| Clean named owns correct VA (no plate collision) | **Yes** (all four; twins re-express same CF) |
| Body-size arithmetic (inclusive) | **Yes** (see unit sections) |
| PodCopy Elem12 **EAX/ECX / 3 dwords** ≠ PodCopy 0x28 **EAX/EDX / 10 dwords** | **Holds** — dual B trap explicit; ADV re-confirms |
| UninitCopy 0x28 leaf is `00409f30` not `00409f50`; stride +0x28 both cursors | **Holds** |
| Complete dtor ≠ scalar (no free host); RTTI product names sealed | **Holds** for both UI units |
| Terminal honesty | **false** on all duals / cleans / this ADV |
| Runtime Confirmed | **Not claimed** |

---

## Unit 1 — `0x00409f50` StdVector_PodCopyElement_Elem12_Inferred

### Body / ABI seal (independent)

```text
0x00409f64 − 0x00409f50 + 1 = 0x15 = 21 B  (inclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x00409f50`–`0x00409f64` inclusive (**21 B** / `0x15`); pad `CC` | **Confirmed** (size math + raw re-verify plate) |
| Full body bytes `85 C0 74 10 8B 11 89 10 8B 51 04 89 50 04 8B 49 08 89 48 08 C3` | **Confirmed** (raw plate; 21 B) |
| **EAX** = dest; **ECX** = src; bare **`C3`**; no stack args | **Confirmed** (machine + ConstructN/range call-site plates) |
| Null dest → skip; else **3 dwords** (0/4/8) → **0x0C** | **Confirmed** |
| Callers (2): ConstructN Elem12 `00409db0` @ `00409de8`; range `0040a590` @ `0040a5c8` (both +0x0C) | **Accepted** (raw call-site memory) |
| Leaf (no callees); not ConstructN; not PodCopy 0x28 | **Holds** — dual B rejects merge |
| Name `_Inferred` / product open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
// Machine: EAX=dest, ECX=src (decomp __fastcall param_1 = src)
void FUN_00409f50(undefined4 *param_1 /*src=ECX*/)
{
  undefined4 *in_EAX; // dest
  if (in_EAX != 0) {
    *in_EAX = *param_1;
    in_EAX[1] = param_1[1];
    in_EAX[2] = param_1[2];
  }
  return; // C3
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x00409f50`** (21 B) |
| CF rewrite | **Match** — null-dst no-op; `memcpy(dest,src,0x0C)` ≡ 3 dwords |
| Scaffold twin | Re-expresses same CF — **OK** |
| ABI plate comment | Explicit EAX/ECX vs peer 0x28 EAX/EDX trap |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — leaf CF/ABI/size High |
| B adversarial | accept-with-gaps | **Agree** — EAX/EDX-merge / 10-dword / thiscall / ConstructN-loop / always-copy attacks falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**. Residual: product POD English only.

---

## Unit 2 — `0x0040a520` StdVector_UninitializedCopy_Elem0x28_Inferred

### Body / ABI seal (independent)

```text
0x0040a584 − 0x0040a520 + 1 = 0x65 = 101 B  (inclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x0040a520`–`0x0040a584` inclusive (**101 B** / `0x65`) | **Confirmed** |
| **ECX** = src_end; stack begin + dest; **EAX** = advanced dest; bare **`C3`** | **Confirmed** (assembly plate + InsertN call sites) |
| Free helper — **not** vector-object thiscall despite decomp label | **Confirmed** (no begin/end/capacity field reads) |
| Loop: while begin≠end; PodCopy `00409f30`(EAX=dest,EDX=src); both **+0x28** | **Confirmed** (`MOV EDX,ESI; MOV EAX,EDI; CALL 00409f30; ADD …,0x28`) |
| SEH `LAB_009bd0b0`; try 0 → −1 | **Confirmed** |
| Callers: InsertN `00408050` (2 sites) + trampoline `00409ae0` (xref_count=3) | **Accepted** (raw call-site plate) |
| Not ConstructN / not Elem12 range `0040a590` / not Pod28-0x1c twin | **Holds** — dual B rejects |
| Name `_Inferred` / product open | **Correct hygiene** |

### Live / raw decompile (independent summary)

```c
// Decomp empty FUN_00409f30() + __thiscall overridden by bytes:
//   MOV EDI,[ebp+0xc]; MOV EBX,ECX; MOV ESI,[ebp+8]
//   loop: MOV EDX,ESI; MOV EAX,EDI; CALL 00409f30; ADD EDI,0x28; ADD ESI,0x28
//   MOV EAX,EDI; RET
int FUN_0040a520(int param_1 /*end*/, int param_2 /*begin*/, int param_3 /*dest*/)
{
  // SEH LAB_009bd0b0
  for (; param_2 != param_1; param_2 += 0x28) {
    FUN_00409f30(); // machine: EAX=dest, EDX=src
    param_3 += 0x28;
  }
  return param_3;
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x0040a520`** (101 B) |
| CF rewrite | **Match** — half-open range, stride 0x28, leaf 0x28 PodCopy, return dest_end |
| SEH | Omitted honestly from clean body |
| Scaffold twin | Re-expresses same CF (calls `FUN_00409f30`) — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — range CF/ABI/stride/leaf High |
| B adversarial | accept-with-gaps | **Agree** — true-thiscall / stride0x0C / fill-n / ConstructN / ret0xC / twin-merge attacks falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**. Residual: product type + undualed trampoline/InsertN/Elem12-range twin.

---

## Unit 3 — `0x00834520` CWndVehicle_CompleteDtor

### Body / ABI seal (independent)

```text
0x008345b1 − 0x00834520 + 1 = 0x92 = 146 B  (inclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x00834520`–`0x008345b1` inclusive (**146 B** / `0x92`); `CC` then ctor `0x008345c0` | **Confirmed** |
| **`__thiscall`** ECX=this (`8B F9` → EDI); SEH `LAB_009b4563`; bare **`C3`**; void | **Confirmed** |
| Installs vtbl **`PTR_FUN_00a6fbcc`** | **Confirmed** (`C7 07 CC FB A6 00`) |
| Nested `@+0x2A8` (`this[0xAA]`): flag/copy/stamp/`FUN_0076c4d0` + dual vcall | **Confirmed** (raw decomp ≡ re-verify) |
| `FUN_00833d50` with **EDI=this** (not ECX thiscall) then base `FUN_0078ca80` | **Confirmed** (dual B EDI narrow; epilogue `8B CF` before base) |
| Does **not** free host | **Confirmed** — free is scalar peer `004160d0` only |
| Sole caller scalar `004160d0` @ `004160d3` (vtbl[0]) | **Accepted** |
| RTTI COL → **`.?AVCWndVehicle@@`** | **Confirmed** (dual re-verify COL chain) |
| Product name sealed (not `_Inferred`) | **Correct** |

### Live / raw decompile (independent summary)

```c
void __fastcall FUN_00834520(undefined4 *param_1 /*this*/)
{
  // SEH LAB_009b4563; EDI=this
  *param_1 = &PTR_FUN_00a6fbcc;
  iVar1 = param_1[0xaa]; // +0x2A8
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x48) = 1;
    *(undefined4 *)(iVar1 + 0x44) = *(undefined4 *)(iVar1 + 0x40);
    FUN_0076c4d0(); // machine: nested+0x10
    // binder {00a9f4d8, nested}; vcall +0x20 / +0x10(0) on *(nested+8)
  }
  FUN_00833d50(); // machine: EDI=this
  FUN_0078ca80(); // base CNDUIWndBuffered complete
  return; // C3 — no operator_delete(this)
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x00834520`** (146 B) |
| CF rewrite | **Match** — vtbl, nested notify, EDI helper call, base chain; no host free |
| Nested index | `self[0xAA]` ≡ +0x2A8 — **OK** |
| Scaffold twin | Forwards to named clean — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — complete-dtor CF/ABI/vtbl/RTTI High |
| B adversarial | accept-with-gaps | **Agree** — scalar/vector/host-free/cdecl/wrong-class attacks falsified; nested double-notify sealed |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**. Residual: nested/`FUN_00833d50` product English + undualed helpers.

---

## Unit 4 — `0x00832fa0` CWndWaypointIcon_CompleteDtor

### Body / ABI seal (independent)

```text
0x0083300f − 0x00832fa0 + 1 = 0x70 = 112 B  (inclusive end)
```

| Claim | Independent result |
|---|---|
| Range `0x00832fa0`–`0x0083300f` inclusive (**112 B** / `0x70`); next `0x00833010` | **Confirmed** |
| **`__thiscall`** ECX=this (`8B F1` → ESI); SEH `LAB_009b33be`; bare **`C3`**; void | **Confirmed** |
| Installs vtbl **`PTR_FUN_00a7000c`** | **Confirmed** (`C7 06 0C 00 A7 00`) |
| Owned `@+0x488` (`this[0x122]`): if non-null `FUN_0096efd0` + `operator_delete`; **always** null field | **Confirmed** (raw + false-noreturn correction) |
| Base `FUN_007b5be0` (direct; not via `0078ca80`) | **Confirmed** — distinct from CWndVehicle base path |
| Does **not** free host | **Confirmed** — free is scalar peer `00416350` only |
| Sole caller scalar `00416350` @ `00416353` | **Accepted** |
| RTTI COL → **`.?AVCWndWaypointIcon@@`** | **Confirmed** (closes scaffold Class_00a7000c for this body) |
| Product name sealed | **Correct** |

### Live / raw decompile (independent summary)

```c
void __fastcall FUN_00832fa0(undefined4 *param_1 /*this*/)
{
  // SEH LAB_009b33be; ESI=this
  *param_1 = &PTR_FUN_00a7000c;
  pvVar1 = (void *)param_1[0x122]; // +0x488
  if (pvVar1 != 0) {
    FUN_0096efd0();
    /* Ghidra false-noreturn — bytes: ADD ESP,4 then fall through */
    operator_delete(pvVar1);
  }
  param_1[0x122] = 0; // always
  FUN_007b5be0(); // base window complete
  return; // C3 — no operator_delete(this)
}
```

### Clean fidelity

| Item | Result |
|---|---|
| Named clean VA / size plate | **Owns `0x00832fa0`** (112 B) |
| CF rewrite | **Match** — vtbl, free-then-always-null, base; false-noreturn documented |
| Owned index | `self[0x122]` ≡ +0x488 — **OK** |
| Scaffold twin | Forwards to named clean — **OK** |

### Dual A/B quality

| Path | Verdict | ADV |
|---|---|---|
| A fidelity | accept-with-gaps | **Agree** — complete-dtor CF/ABI/vtbl/RTTI/owned path High |
| B adversarial | accept-with-gaps | **Agree** — scalar/vector/host-free/cdecl/false-noreturn/skip-null attacks falsified |

### Unit verdict

**PASS** — keep **`accept-with-gaps`**. Residual: owned-block English + undualed base/release; scalar rename residual out-of-scope.

---

## Findings (non-blocking)

| # | Severity | Finding | Impact |
|---|---|---|---|
| F1 | Low (port) | **PodCopy ABI family trap:** Elem12 leaf `00409f50` is **EAX dest / ECX src / 3 dwords**; peer 0x28 leaf `00409f30` is **EAX dest / EDX src / 10 dwords**. Dual B seals both; naive “all PodCopy are EAX/EDX” merge corrupts ConstructN Elem12. | Keep leaves distinct in AutoCore ports. |
| F2 | Low (port) | **CWndVehicle helper EDI ABI:** `FUN_00833d50` consumes **EDI=this** (entry preserved); not standard ECX thiscall at call site. Clean correctly calls with no formal this. | Port must preserve EDI or rewrite helper signature. |
| F3 | Info | **Decomp traps correctly overridden:** UninitCopy false `__thiscall` + empty `FUN_00409f30()`; Waypoint Ghidra false-noreturn on `operator_delete` (bytes fall through after `ADD ESP,4`). | Duals/cleans honest; raw decomp alone is insufficient. |
| F4 | Info | **Nested double-notify** on CWndVehicle: complete notifies `@+0x2A8` then `FUN_00833d50` may re-notify same nested. Dual B sealed as odd behavior. | Preserve both paths; do not “dedupe” without evidence. |
| F5 | Info | **Matrix domain taxonomy:** VERIFICATION_MATRIX rows L297–300 tag all four under `skills-abilities` (WQ-009 residual path). Duals correctly classify as vector POD util + UI window complete dtors. | Ledger taxonomy residual only; not dual overclaim. |
| F6 | Info | **Parent residual** (expected): Elem12 range twin `0040a590`; trampoline `00409ae0`; InsertN `00408050`; vehicle helpers `00833d50`/`0078ca80`/`0076c4d0`; waypoint `0096efd0`/`007b5be0`; scalar rename residual on `00416350`. | Not dual overclaim. |
| F7 | Info | Product English open on both vector units (`_Inferred`); UI product RTTI sealed; nested/owned layout English open. | Correct Terminal **false**. |

No CF reject. No dual A↔B contradiction on sealed ABI/role. No clean plate VA collision. No Terminal overclaim. No Runtime Confirmed claim.

---

## Overall unit scorecard

| Unit | Dual A | Dual B | ADV unit | Keep dual verdict? |
|---|---|---|---|---|
| `aa_00409f50` PodCopy Elem12 | accept-with-gaps | accept-with-gaps | **PASS** | Yes |
| `aa_0040a520` UninitCopy 0x28 | accept-with-gaps | accept-with-gaps | **PASS** | Yes |
| `aa_00834520` CWndVehicle CompleteDtor | accept-with-gaps | accept-with-gaps | **PASS** | Yes |
| `aa_00832fa0` CWndWaypointIcon CompleteDtor | accept-with-gaps | accept-with-gaps | **PASS** | Yes |

**Overall:** **PASS-WITH-FINDINGS** — dual seals stand; findings are port traps + expected residual, not reject reasons.

---

## WQ-007 matrix re-confirm (line numbers)

Independent line-proof that the two requested WQ-007 residual units appear in `docs/reconstruction/VERIFICATION_MATRIX.md`:

| Stable ID | Canonical name | Main matrix row | Residual index row |
|---|---|---|---|
| `aa_00411180` | `StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred` | **L93** | **L377** (`**present**`) |
| `aa_007f5120` | `Input_KeyCodeToDisplayName` | **L97** | **L379** (`**present**`) |

Both sit under the WQ-007 residual dual block (matrix L83–98 main rows; durable index L361–382, 16/16). Status remains **partial** with dual A/B sealed and runtime open — consistent with Terminal **false**.

---

## Process notes

- Independent ADV only; **not** dual author of WQ9J-A / WQ9J-B.
- Read dual A/B + agent reports + raw (+ re-verify appends) + annotated + named/twin cleans for all four units.
- **No** `disassemble_bytes`; **no** parent ledger edits; **no** dual rewrites; **no** Launcher.
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
