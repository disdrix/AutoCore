# Review B (skeptical / adversarial): `aa_0055f520` LocalWorklist16_Init_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055f520` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-R) |
| **Counterpart** | `reviews/A_aa_0055f520_LocalWorklist16_Init_Inferred.md` |
| **Scratch** | `tmp/a_0055f520.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the pair-list commit outer | **Falsified** — that is `006297e0`; this is nested worklist init |
| 2 | Same as stride-8 bind worklist release | **Falsified** — sibling family; this is **init**, stride **16**, `ret 4` |
| 3 | No stack formals / plain ret | **Falsified** — `MOV EBX,[esp+8]`; epilogue `C2 04 00` |
| 4 | Always heap alloc via vcall | **Falsified** — bump path when remaining ≥ size |
| 5 | High bit means "tagged owned" | **Overstated** — high bit set so release **skips** tag free (`JS` on release) |
| 6 | Decompiler size is incomplete | **Partially true** — machine align16; equivalent for `count*16` already aligned; clean documents both |
| 7 | Product allocator name is retail | **Overstated** — `DAT_00b05060` only; `_Inferred` role name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Init role / stride 16 | **High** | Wrong slab size in pair-list path |
| thiscall + ret 4 | **High** | ABI break |
| Arena bump vs vtbl+0x24 | **High** | Leak / arena corruption |
| High-bit stamp | **High** | Double free on release |
| Allocator product type | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
PUSH EBX; count=[esp+8]; size=align16(count*16); MOV ESI,ECX
desc zero + 0x80000000 seed
if remaining < size: vtbl+0x24 else bump
stamp desc; MOV EAX,ESI; POP ESI/EBX; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Align residual documented in clean. Caller dual requires init before stride-0x10 iterators.

---

## 4. Surviving contract for AutoCore

```
// Before pair-list worklist use (Phys_CommitPairListStorage):
LocalWorklist16_Init_Inferred(&stack_desc, count);
// Must preserve: stride*16 size, bump-vs-alloc, high-bit on desc[+8], ret 4.
// Pair with LocalWorklist16_Release_Inferred after use.
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/role sealed; align16 documented in clean → **accept**.
