# Review B (skeptical / adversarial): `aa_0074c9c0` Bounds_AccumulateTransformedLocal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074c9c0` |
| **Review type** | Skeptical / adversarial (Path B) |
| **Date** | `2026-07-29` (W21-O) |
| **Counterpart** | `reviews/A_aa_0074c9c0_Bounds_AccumulateTransformedLocal.md` |
| **Verdict** | **accept-with-gaps** on sealed CF/ABI; reject TeleportIn-only name and any claim of full matrix ownership |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Ghidra `void(int,float*,int)` is complete ABI | **Falsified** — ECX dest required; `ret 12`; call sites load ECX before call |
| 2 | Parent-seed name is TeleportIn-only glue | **Rejected as exclusive** — many mesh callers (`004bdb*`, `004be*`, `004bf*`) also call |
| 3 | Function always runs | **Falsified** — `local[+0x2c]!=0` skips entire body |
| 4 | Always uses full 3D scale ratio | **Falsified** — both `+0xb8==0` uses **X-only** ratio |
| 5 | `DAT_00a0f298` is 1.0 or epsilon | **Falsified** — bytes `3f000000` = **0.5f** |
| 6 | Dest gate English “dirty” vs “valid” | **Contested** — byte sealed; English open (nonzero skips on **local**; cleared on **dest**) |
| 7 | Clean C++ min/max ≡ every float select | **Overstated** — decompile uses pointer-select min/max; simplified `if (v < min)` is **Probable** not bit-proven |
| 8 | This dual owns `FUN_0044b5c0` / matrix math | **Rejected** — callee not owned; behavior treated as black-box matrix producer |
| 9 | Returns useful EAX | **No claim** — void; no sealed return |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX + ret 12 + 3 stack | **High** | Wrong call convention → stack smash |
| Gate +0x2c | **High** | Spurious merges / missed |
| Sphere merge 0.5f | **High** | Wrong bounds growth |
| 8-corner loop structure | **High** | Incomplete AABB |
| Scale flag/path | **High** | Wrong world radius |
| AABB float-select bit-identity | **Medium** | Rare corner clamps |
| Product names | **Low** | Docs only |
| Matrix helper semantics | **Low–Med** | Transform wrong if 0044b5c0 misread |

---

## 3. Cross-check against call site `0x004bdb*`

```
obj = vtbl+0x0c()
bounds = vtbl+0x48(obj)
push obj
push bounds
push &DAT_00d1eb60
lea ecx, [owner+0x414]
call FUN_0074c9c0   ; ret 12
```

Matches sealed stack order: xformRef, local, scaleSrc + ECX dest.

---

## 4. Surviving contract for AutoCore

```
// Client bounds accumulate (graphics):
//   Bounds_AccumulateTransformedLocal(dest /*ECX*/, xformRef, local, scaleSrc)
// Preconditions:
//   local[+0x2c]==0 or no-op
// Effects:
//   dest sphere merged; dest AABB expanded by transformed local AABB corners;
//   dest[+0x2c]=0; dest[+0x10]=XZ extent metric
// Do not invent:
//   network packets, physics island steps, TeleportIn-only semantics
```

---

## 5. Open questions (narrow)

1. Product type names.
2. Dual `FUN_0044b5c0` (matrix from xformRef/scaleSrc flags at `+0xbc`).
3. What initializes dest AABB before first accumulate (seed values).
4. Runtime / bit-diff of AABB clamp chain.

**Verdict:** **accept-with-gaps** — ABI + core CF sealed; reject single-caller naming and bit-exact AABB overclaim without further select proof.
