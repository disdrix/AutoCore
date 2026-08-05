# Review B (skeptical / adversarial): `aa_0055f590` LocalWorklist16_Release_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055f590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-R) |
| **Counterpart** | `reviews/A_aa_0055f590_LocalWorklist16_Release_Inferred.md` |
| **Scratch** | `tmp/a_0055f590.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the pair-list commit outer | **Falsified** — that is `006297e0`; this is nested teardown |
| 2 | Identical to `0055f4c0` LocalWorklist_Release | **Partially** — same CF shape/allocator; **stride 16 vs 8** (shl4 vs *8) |
| 3 | Stack formals / `ret 4` | **Falsified** — `MOV ESI,ECX`; plain `C3` ret |
| 4 | Always heap free via vcall | **Falsified** — bump path when size==0 or slab≠current |
| 5 | Always runs tag free | **Falsified** — skipped when `desc[+8] < 0` (`JS`); init always sets high bit so normal path skips |
| 6 | Decompiler `<<4` is complete for tag size | **Overstated** — machine `AND 0x7fffffff` first; clean corrected |
| 7 | Decompiler bare `*0x10` for slab size is complete | **Overstated** — machine align16 (`+0xf & ~0xf`); clean corrected |
| 8 | Product allocator name is retail | **Overstated** — `DAT_00b05060` only; `_Inferred` role name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Teardown role | **High** | Leak / double-free |
| ECX desc / ret 0 | **High** | ABI break |
| Slab branch | **High** | Arena corruption |
| Tag free + mask + 0x12 | **High** | Heap bookkeeping |
| Stride 16 vs sibling *8 | **High** | Wrong free size |
| Allocator product type | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
PUSH ESI; MOV ESI,ECX
size = align16(desc[4]*0x10)
branch bump vs vtbl+0x28
if desc[2]>=0: vtbl+0x14(*desc, (desc[2]&0x7fffffff)<<4, 0x12)
POP EDI; POP ESI; RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Align + mask residuals documented and fixed in clean. Caller dual requires always-call after init.

---

## 4. Surviving contract for AutoCore

```
// After pair-list worklist use (Phys_CommitPairListStorage):
LocalWorklist16_Release_Inferred(&stack_worklist_desc);
// Must preserve: align16(count*16), bump-vs-free, tag 0x12 free with 0x7fffffff mask + <<4.
// Do not substitute stride-8 LocalWorklist_Release (0055f4c0) — wrong element size.
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/role sealed; decompiler elisions corrected in clean → **accept**.
