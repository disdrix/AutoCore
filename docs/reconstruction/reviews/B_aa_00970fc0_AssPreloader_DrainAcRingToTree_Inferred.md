# Review B (skeptical / adversarial): `aa_00970fc0` AssPreloader_DrainAcRingToTree_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970fc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-AD) |
| **Counterpart** | `reviews/A_aa_00970fc0_AssPreloader_DrainAcRingToTree_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `void FUN_00970fc0(void)` means no host / no inputs | **Falsified** — `MOV EBX,EAX` at entry; both callers `MOV EAX,host` before call |
| 2 | `local_c` is uninitialized garbage | **Falsified** — `FUN_0043e850` writes key dword + flag byte into EDI out entry before branch; init zero via `FUN_0043d6f0` |
| 3 | Tree base is `host` itself | **Falsified** — after first successful pop, `ADD EBX,0xDC`; success path `MOV EDI,EBX` into find-or-insert |
| 4 | Ring is at host+0x4C or +0x7C (other AssPreloader rings) | **Falsified** — `LEA ESI,[EBX+0xAC]`; matches W33-O/W36-D ring push sites for `+0xAC` |
| 5 | Both flag polarities call find-or-insert | **Falsified** — `JZ` fail path → `FUN_0043d770` only; success path only stores 1 |
| 6 | Scaffold `Named_CalleeOf_Named_assPreloader_*` is product name | **Falsified** — no string/RTTI on this VA; structural `_Inferred` only |
| 7 | This function has stack formals / RET N | **Falsified** — bare `C3`; no `RET imm16` |
| 8 | Fail path uses ECX=tree | **Falsified** — fail: `MOV EAX,EBX` then call; ECX remains `&local.key` from pre-branch `LEA` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Drain role on +0xAC → +0xDC | **High** | Wrong preload stage order |
| Host EAX ABI | **High** | Silent wrong-this ports |
| Flag branch + value=1 | **High** | Wrong tree membership |
| AssPreloader family link | **High** | Orphan unit |
| Fail helper product role | **Low** | Mis-model cascade/erase |
| Method English | **Low** | Naming churn |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// Entry: 55 8B EC 83 E4 F8 83 EC 0C 53 56 8B D8 57 ... C3  (101 B, pad CC)
// Callers:
//   009712b2: MOV EAX,EBP; CALL FUN_00970fc0  (W32-J child-asset preload loop)
//   00972182: MOV EAX,EBP; CALL FUN_00970fc0  (W32-K worker loop)
// Callees: 0043d6f0 (zero entry), 0043e850 (pop), 0043d700 (insert), 0043d770 (fail)
// Pushers of +0xAC: W33-O seed {key,1}, W36-D side push {key,0}
```

Live decompile 2026-08-04 ≡ raw 2026-07-23 CF skeleton; body hex seals EAX host, +0xAC/+0xDC, and flag branch.

---

## 4. Surviving contract for AutoCore

```
// Port as AssPreloader drain (register host, not thiscall):
//   host in EAX-equivalent; no stack args.
// Must: pop ring host+0xAC until empty;
//       success flag → find-or-insert tree host+0xDC, value=1;
//       fail flag → FUN_0043d770(tree,key).
// Do not treat decompiler void signature as no host.
// Do not skip drain before child-asset / worker steps that expect a clean ring.
// Do not confuse +0xAC with success ring +0x4C or fail list +0x7C.
```

---

## 5. Verdict

Adversarial pass confirms A on host ABI, ring/tree offsets, flag polarity split, and caller set. Residual fail-helper product English + nested duals + runtime → **accept-with-gaps**.
