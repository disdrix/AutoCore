# Review B (skeptical / adversarial): `aa_004cb3e0` CVOGObject_StoreLocalPosition4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb3e0` |
| **VA** | `0x004cb3e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B **create**) |
| **Counterpart** | `reviews/A_aa_004cb3e0_CVOGObject_StoreLocalPosition4_Inferred.md` |
| **Scratch** | `reviews/a_004cb3e0.md` |
| **Verdict** | **accept-with-gaps** — pure store leaf + 2 callers sealed; product name open |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Body owns NaN trap / `"VOG_DEBUG_STOP"` | Scaffold alias `Named_CalleeOf_Named_VOG_DEBUG_STOP_*` | **Falsified** — trap lives in parent `004c3a40`; this leaf has no calls, no string refs |
| 2 | Body owns `0xC7` / `+0xb8` gate | Collapse with gated parent | **Falsified** — straight-line stores only; gate is caller-side |
| 3 | Writes thr / steer / HB / drive axes | Drive-path association via parent | **Falsified** — only `+0x240..+0x24c` |
| 4 | Stores only xyz (3 floats) | “Position is vec3” folklore | **Falsified** — fourth dword always written to `+0x24c` |
| 5 | SSE / `movaps` bulk copy of 16 B | Modern vectorize assumption | **Falsified** — four scalar `mov` pairs |
| 6 | `ret` / no stack cleanup | Confuse with no-arg hooks | **Falsified** — `c2 04 00` (`ret 4`) |
| 7 | Exclusive callee of gated parent only | “Always gated” port myth | **Falsified** — also `FUN_005cd3b0` @ `005ce8a3` |
| 8 | Inlines into parent (no real leaf) | Decompiler elision fear | **Falsified** — separate function body + real `CALL` sites |
| 9 | Uses FPU loads (`fld`/`fstp`) | Float-typed store myth | **Falsified** — integer `mov` of dwords (bit-identical for f32) |
| 10 | Product name sealed | Promote without RTTI | **Not sealed** — keep `_Inferred` / `FUN_*` |
| 11 | Dead / unused | Drop from pose map | **Falsified** — **2** live unconditional CALL sites |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Machine body / span / four offsets | **High** | Corrupt wrong object fields |
| ABI thiscall + `ret 4` | **High** | Stack imbalance in port |
| No gate / no NaN in **this** VA | **High** | Fake early-out or double-gate |
| Always 4 dwords including W | **High** | Truncated vec3 ports |
| Caller count = 2 (gated + bypass) | **High** | “Always gated” false security |
| Label “local position” vs generic float4 | **Probable** | Misname only; layout still correct |
| Product English name | **Low / Open** | Naming only |
| Bypass semantics of `005cd3b0` | **Out of scope** | Incomplete writer inventory narrative |

---

## 3. Cross-check against raw + bytes

```
// clean ≡ raw ≡ machine (2026-07-29)
// 004cb3e0..004cb409: four dword stores + ret 4
void StoreLocalPosition4(Object *self, const uint32_t *in /* float[4] */)
{
    self[+0x240] = in[0];
    self[+0x244] = in[1];
    self[+0x248] = in[2];
    self[+0x24c] = in[3];
}
```

Live `decompile_function` ≡ frozen raw scaffold ≡ `read_memory` opcode stream.

**Parent contrast (not this body):**

| Unit | VA | Extra work before/around store |
|---|---|---|
| Gated writer | `0x004c3a40` | NaN xyz + trap; `typeOff+0xb8 & 0xC7` gate; then **CALL this** |
| **This leaf** | `0x004cb3e0` | **None** — store only |
| Bypass caller | `0x005cd3b0` | Own CF (not dualed); still **CALL this** |

---

## 4. Surviving contract for AutoCore

```
CVOGObject_StoreLocalPosition4_Inferred(object, in /* float[4] as 4×u32 */):
  object[+0x240] = in[0]
  object[+0x244] = in[1]
  object[+0x248] = in[2]
  object[+0x24c] = in[3]
  // no NaN, no flag gate, no return value

// Static callers:
//   FUN_004c3a40 @ 004c3aa6  (gated SetLocalPosition4)
//   FUN_005cd3b0 @ 005ce8a3  (bypass path)

// Port rules:
//   * Do NOT fold gate/NaN into this leaf unless matching a merged image
//   * Do NOT drop W store
//   * Do NOT assume sole caller is the gated parent
//   * Bit-identical f32 copy via u32 mov is correct
```

**Port tests that matter:**

* After call, four dwords at `object+0x240` equal source buffer.
* Null `in` or null `this` → fault (no retail null checks).
* Gating is a **caller** concern; ports that always call this leaf skip the gate on purpose (match `005cd3b0` path).

---

## 5. Open questions

1. Runtime / differential under live objects.
2. PDB / retail symbol.
3. Full English meaning of the `+0x240` block (pos vs padded pose) — consumer duals.
4. Complete dual of `FUN_005cd3b0` (when owned separately).
5. Whether any **data**/vtbl slot also targets this VA (code xrefs sealed at 2 CALLs this pass).

**Verdict:** **accept-with-gaps** — adversarial attacks on hidden gate/NaN, 3-float-only store, exclusive gated ownership, and dead-code claim **closed**; product name + full reader/bypass CF remain open.
