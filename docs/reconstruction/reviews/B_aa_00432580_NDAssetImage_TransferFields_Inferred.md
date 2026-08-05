# Review B (skeptical / adversarial): `aa_00432580` NDAssetImage_TransferFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00432580` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00432580_NDAssetImage_TransferFields_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Pure thiscall / ECX=this only | Stack `mov ebp,[esp+8]`; **ret 4**; EBX=src | **Falsified** pure-thiscall — **dest stack + src EBX** |
| 2 | Deep copy that leaves src intact | Explicit zero of src blocks after copy | **Falsified** copy — **move/steal** |
| 3 | Copies entire object including vtbl | Starts at +8; +0 not in movsd; vtbl untouched | **Confirmed** skips +0 |
| 4 | Block sizes are approximate | `mov ecx,10` / `mov ecx,0x5F` exact | **Exact** 40 B + 380 B |
| 5 | Pre-clear is optional | Unconditional call; fail returns early | **Required** gate |
| 6 | Name without `_Inferred` product-proven | No RTTI at this VA; sibling name is role label | **Needs `_Inferred`** |
| 7 | Unit is filesystem IO | Callers are decode/flip image paths | **Reject** IO alias — **buffer ownership** |
| 8 | Runtime verified | No live transfer capture this dual | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI dest stack + src EBX + ret 4 | **High** | Wrong call-site register / stack smash |
| Move semantics (zero src) | **High** | Double-free if port keeps src |
| Block sizes 10 / 0x5F dwords | **High** | Truncated or overrun copy |
| Pre-clear via FUN_004321b0 | **High** | Leak dest old buffers |
| Product field labels | **Medium** | Doc-only |
| FUN_004321b0 gate (+0x38) | **Medium** (out of OWN) | Silent fail on “busy” dest |

---

## 3. Cross-check against raw + bytes

```
raw decompile:
  if (char)FUN_004321b0()==0: return
  copy 10 dwords +8; copy 0x5F dwords +0x30
  copy +4,+0x1ac,+0x1b0,+0x1b4
  zero src equivalents; return 1

bytes:
  mov ebp,[esp+8]; mov esi,ebp; call 0x004321b0
  test al; jz ret4
  rep movsd ecx=10; rep movsd ecx=0x5F
  zero; mov al,1; ret 4
```

Clean plate must keep **EBX=src** contract; portable C cannot invent missing src formal without documenting the register.

---

## 4. Surviving contract for AutoCore

```csharp
// Client asset/image path. After decode into temp, commit into destination:
//   TransferFields(dest, srcInEbx)
// Pre-clear dest owned buffers (FUN_004321b0). On failure return false.
// Move blocks: +0x08 (40B), +0x30 (380B), +4, +0x1ac, +0x1b0, +0x1b4.
// Zero those fields on src so temp dtor is free of double-free.
// Do not copy vtbl at +0.
```

- Do **not** treat as deep-copy helper that retains src ownership.
- Do **not** assume dest may skip pre-clear.
- Server AutoCore image decode may reimplement move with the same field sets if porting client assets.

---

## 5. Residual risks

1. `FUN_004321b0` not OWN — gate when `+0x38 != 0` returns 0 without frees.
2. Product field names for header/mid blocks open.
3. Whether any caller relies on partial transfer if pre-clear fails mid-owned-set (callee should be all-or-nothing; not re-proven here).
4. No runtime differential this dual.

**Verdict:** **accept-with-gaps** — adversarial pass does not break CF/ABI seal; naming stays inferred.
