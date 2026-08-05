# Review B (skeptical / adversarial): `aa_005b4260` Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b4260` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-O) |
| **Counterpart** | `reviews/A_aa_005b4260_Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the live construction path | **Falsified as live** — zero code xrefs; hosts call `FUN_005b3f60` then separate populate |
| 2 | Fewer/more than five stack args | **Falsified** — final `C2 14 00` (`ret 0x14`) |
| 3 | SEH is decompiler fiction | **Falsified** — handler imm `0x009a6860`, fs:[0] link/unlink in bytes |
| 4 | Shell differs from default ctor | **Falsified** — same vtbl, LEA +0x10, buy, head/size, movss F4 |
| 5 | Populate args product-named | **Overstated** — `FUN_005b3fa0` not owned; structural only |
| 6 | Retail symbol known | **Overstated** — structural inferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Shell + populate + ret 0x14 | **High** | Wrong ctor port if ever used |
| Zero live callers | **High** | Wasted port priority only |
| Populate semantics | **Low** | Wrong grid/fill if reimplemented here |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against bytes + twin

```
; vs live host FUN_004cd8f0
new(0x30) → FUN_005b3f60 → store → FUN_005b3fa0(...)
; NOT → FUN_005b4260
```

```
; 005b4260 = default shell + CALL 005b3fa0 + ret 0x14
; same list LEA + vtbl as 005b3f60 / destroy list@+0x10 in 005b3b20
```

---

## 4. Surviving contract for AutoCore

```
// Prefer live split:
//   default = Obj_DefaultCtor_... (005b3f60)
//   populate = FUN_005b3fa0 (separate unit)
// This unit is optional convenience; do not assume callers exist.
// If ported: preserve SEH scope around populate; clean 5 stack args.
```

---

## 5. Verdict

Adversarial pass **confirms** A on bytes/ABI and **rejects** “primary live ctor” claim → **accept-with-gaps** (dead convenience + product open).
