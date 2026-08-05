# Review B (skeptical / adversarial): `aa_0043d570` StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d570` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W38-A) |
| **Counterpart** | `reviews/A_aa_0043d570_StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Leaf find-only (like sibling `0043d5e0`) | **Falsified** — miss path calls `0043c8b0` + `0043d7d0`; mutates tree |
| 2 | Same ABI as W37-Q op[] (`ECX` map / `EAX` key*) | **Falsified** — bytes use **EDI** map / **EDX** key*; first insn `MOV ECX,[EDI+4]` |
| 3 | Same ABI as W37-M find (`ECX` map / `EBX` key* / `EAX` out_it) | **Falsified** — returns mapped* in EAX; no out_it write; EDI/EDX formals |
| 4 | Pure lower_bound (no equality) | **Falsified** — hit gate `*key >= cand.key` after lower_bound ⇒ equality |
| 5 | Signed int key | **Falsified** — `JNB`/`JB` path; decompiler `uint` |
| 6 | isnil@+0x15 / +0x21 / +0x29 | **Falsified** — `80 78 19 00` → **+0x19** Val12 |
| 7 | Stack thiscall `RET 4` / `RET 8` | **Falsified** — plain `C3`; no stack formals |
| 8 | Scaffold assPreloader product name | **Rejected** — caller context only; structural StdTree op[] name |
| 9 | Returns whole node (iterator) | **Falsified** — hit `LEA EAX,[ESI+0x10]`; miss `ADD EAX,0x10` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI map + EDX key* + EAX mapped* + RET | **High** | Caller ABI crash |
| op[] get-or-insert (not find-only) | **High** | Miss drops insert |
| Val12 isnil/key/mapped layout | **High** | Wrong node family port |
| Unsigned key compare | **High** | Neighbor miss/false hit |
| Insert helper internal ABI | **Medium** | Unowned residual only |
| Product map English | **Inferred/Open** | Naming only |
| Runtime | **Open** | Cache races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  head = *(map+4); walk root parent; equality gate;
  hit → node+0x10; miss → c8b0 + d7d0 → *it+0x10

bytes:
  MOV ECX,[EDI+4]; MOV EAX,[ECX+4]; SUB ESP,18
  isnil [reg+0x19]; key from [EDX]; unsigned CMP [node+0xC]
  CALL 0043c8b0; CALL 0043d7d0; ADD EAX,10 / LEA EAX,[ESI+10]
  ADD ESP,18; RET
```

Live decompile 2026-08-04 ≡ raw 2026-07-23 CF; **bytes win** on register ABI. Body ends exactly at sibling `0043d5e0`.

Call-site corroboration (`0097156b` / `00970bc7`): `LEA EDI, …` tree host then call; store into returned mapped pair — matches op[] return of `val1/val2`.

---

## 4. Surviving contract for AutoCore

```
// Val12 uint-key operator[] (EDI/EDX ABI):
//   EDI = map (head @ +4)
//   EDX = const uint32_t* key
//   EAX = int32_t* mapped (node+0x10)
//   plain RET — do NOT invent RET 4/8 or ECX thiscall
// Do NOT treat as leaf find (miss inserts {key,0,0}).
// Do NOT mix with EAX-key peer 0043bd40 or EBX-key find 0043d5e0 ABI.
// Do NOT use scaffold assPreloader-derived product name.
```

---

## 5. Residual gaps (accepted)

- Full formal ABI of unowned `FUN_0043c8b0` / `FUN_0043d7d0` beyond call-site.
- Product value_type English.
- Runtime / differential.

---

## 6. Verdict

Adversarial pass **confirms** A on ABI/CF/layout/op[] role and rejects find-only / wrong-RET / wrong-isnil / wrong-peer-ABI / scaffold-name claims → **accept-with-gaps**.
