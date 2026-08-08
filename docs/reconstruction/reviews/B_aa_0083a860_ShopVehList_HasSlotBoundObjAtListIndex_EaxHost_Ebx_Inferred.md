# Review B (skeptical / adversarial): `aa_0083a860` ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083a860` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9L-I) |
| **Counterpart** | `reviews/A_aa_0083a860_ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Thiscall ECX=host | **Falsified** — no ECX use for host; `PUSH EAX` then CALL finder |
| 2 | EAX = list_i | **Falsified** — EAX is host (`PUSH EAX`); list_i is **EBX** (caller `MOV EBX,EDI`; finder compares EBX) |
| 3 | Stack formal host only (no EBX) | **Falsified** — decompiler `in_EAX` phantom; sole caller loads EBX before CALL |
| 4 | Returns slot pointer | **Falsified** — `SETNZ AL` / `XOR AL,AL`; bool only |
| 5 | Mutates host or slots | **Falsified** — pure probe: CALL finder + CMP + RET |
| 6 | Is the full reindex | **Falsified** — 27 B predicate; parent `0083ac90` owns reindex |
| 7 | Is the soft-refresh / reload helper | **Falsified** — parent branches to `a880` / `abf0` based on AL |
| 8 | Id base is 0 / not 0x9ca4 | **Falsified** — encoding lives in finder `0083a7d0` + parent dual (`id - 0x9ca4`) |
| 9 | Product name sealed from RTTI here | **Fails** — name from call-graph + prior shopveh duals → `_Inferred` |
| 10 | Runtime Confirmed | **Fails** — open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX host + EBX list_i + AL bool + bare RET | **High** | Wrong ABI / broken reindex branch |
| +0x508 payload gate | **High** | Wrong soft vs reload decision |
| Sole CALL from 0083ac90 id-match | **High** | Mis-attribute ownership |
| Finder 0083a7d0 contract (evidence) | **High** (bytes of a860 + parent dual constants) | Finder residual only |
| Shopveh English | **Med** (parent dual + drive xml scaffold) | Naming only |
| Type at +0x508 | **Open** | Structural ptr only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check

```text
// Sole call site (assembly authority @ 0x0083adc2):
//   0083adbe  MOV EBX, EDI             ; list_i
//   0083adc0  MOV EAX, EBP             ; host*
//   0083adc2  CALL 0x0083a860
//   0083adc7  TEST AL, AL
//   0083adc9  JNZ  0083add7            ; has bound obj → soft path a880
//            else CALL 0083abf0         ; reload
//
// Body is 27 B; every instruction accounted:
//   PUSH EAX / CALL a7d0 / TEST / JZ miss /
//   XOR ECX / CMP [EAX+0x508],ECX / SETNZ CL / MOV AL,CL / RET /
//   XOR AL,AL / RET
```

A ≡ B on live full-body hex + disasm + sole-caller assembly_context. Decompiler `void`/`in_EAX` formals corrected via bytes.

---

## 4. Surviving contract for AutoCore

```text
// Port as pure five-slot occupancy probe (not reindex):
// - EAX = host*, EBX = list_i, AL = bool, bare RET
// - slot = FindSlotByListIndex(host, list_i) via 0083a7d0
// - return slot != null && slot[+0x508] != 0
// Do not treat as thiscall; do not pass list_i in EAX;
// do not mutate; do not invent RTTI name.
// Parent 0083ac90: true → FUN_0083a880(0); false → FUN_0083abf0.
```

---

## 5. Verdict

Adversarial pass confirms A's register ABI, +0x508 gate, dual bare RET, and sole id-match call site. Rejects thiscall / EAX=list_i / mutator / full-reindex overclaims. Residual product English + finder dual → **accept-with-gaps**.
