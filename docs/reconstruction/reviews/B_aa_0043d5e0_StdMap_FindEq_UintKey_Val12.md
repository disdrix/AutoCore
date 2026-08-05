# Review B (skeptical / adversarial): `aa_0043d5e0` StdMap_FindEq_UintKey_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d5e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-M) |
| **Counterpart** | `reviews/A_aa_0043d5e0_StdMap_FindEq_UintKey_Val12.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure lower_bound (no equality) | **Falsified** — final gate `cand.key <= *key` after lower_bound → equality for uint |
| 2 | Stack thiscall `RET 4` / `RET 8` like peers | **Falsified** — body ends plain `C3`; key/out in EBX/EAX |
| 3 | Signed int key | **Falsified** — `JNB`/`JB` unsigned path; decompiler `uint` |
| 4 | isnil@+0x21 / +0x29 / +0x15 (other map variants) | **Falsified** — bytes `80 79 19 00` → **+0x19** Val12 |
| 5 | Scaffold gfxSubPhaseMap name as product | **Rejected** — caller only; structural StdMap name |
| 6 | Mutating / insert helper | **Falsified** — leaf, read-only walk + write out-it |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX map + EBX key* + EAX out* + RET | **High** | Caller ABI crash |
| Exact find (not lower_bound-only) | **High** | Miss/false hit on neighbors |
| Val12 isnil/key layout | **High** | Wrong node family port |
| Product value_type English | **Inferred/Open** | Naming only |
| Runtime | **Open** | Cache races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  head = *(map+4); walk root; equality gate; *out = cand|head

bytes:
  SUB ESP,8; PUSH ESI; MOV ESI,ECX
  head/root load; isnil [reg+0x19]
  key from [EBX]; unsigned CMP [node+0xC]
  *EAX = result; ADD ESP,8; RET
```

Live decompile 2026-08-04 ≡ raw 2026-07-23 CF; **bytes win** on register ABI.

---

## 4. Surviving contract for AutoCore

```
// Val12 uint-key exact find:
//   ECX = map (head @ +4)
//   EBX = const uint32_t* key
//   EAX = node** out_it
//   plain RET — do NOT invent RET 4/8
// Do NOT treat as pure lower_bound (equality gate required).
// Do NOT mix with TFID isnil29 / char-key / signed-int map helpers.
// Do NOT use scaffold gfxSubPhaseMap-derived product name.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/layout and rejects pure-lower_bound / wrong-RET / wrong-isnil / scaffold-name claims → **accept**.
