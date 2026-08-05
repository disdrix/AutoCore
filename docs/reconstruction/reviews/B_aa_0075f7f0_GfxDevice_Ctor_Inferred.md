# Review B (skeptical / adversarial): `aa_0075f7f0` GfxDevice_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075f7f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-R) |
| **Counterpart** | `reviews/A_aa_0075f7f0_GfxDevice_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Classic thiscall on constructed self (ECX=self) | **Falsified** — ECX stored at `self+4` and AddRef'd; self is first **stack** arg (`8B 6C 24 24`) |
| 2 | Zero / one stack formal | **Falsified** — `C2 08 00`; two stack formals (self + device9) |
| 3 | Fills D3DCAPS / present params with live data | **Falsified** — ctor **zeroes** those spans; sole caller copies caps/params **after** return |
| 4 | Multiple callers | **Falsified** — sole xref `FUN_00735c90` @ CreateDevice success path |
| 5 | Object size unknown | **Falsified** — `operator_new(0x7b0)`; highest ctor stores through `+0x770` / flags `+0x7A8` |
| 6 | Product class fully named `gfxDevice` | **Overstated** — structural from path/factory; `_Inferred` only |
| 7 | Scaffold "Incompatible Driver Version" name is product | **Reject** — auto string-parent seed from nearby log line |
| 8 | Same as PalantirEnv ctor | **Falsified** — different size/ABI/slot map; env is `0x198` / W31-P |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete ctor of 0x7b0 host | **High** | Mis-owned port |
| ABI ECX=d3d9 / stack self+device / RET 8 | **High** | Stack imbalance / missed AddRef |
| Caps/present only zeroed here | **High** | Wrong init order |
| PoolHost seed `DAT_00d1f624` | **High** | Break HostBase aux pool |
| Per-slot product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against gfxAdapter CreateDevice path

```
// FUN_00735c90 success arm (~0x00736470):
//   raw = operator_new(0x7b0)
//   devHost = GfxDevice_Ctor(d3d9=adapter+0x48, raw, device9)
//   memcpy caps → host+0x14 and host+0x144
//   copy present params → host+0x2B8
//   stamp flags @ +0x774… from adapter state
// log plate: gfxAdapter.cpp (FSAA / CreateDevice / D3DXCheckVersion)
```

Confirms this VA is **ctor only**; adapter post-wires caps/flags.

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (ECX = IDirect3D9*, not self):
host = GfxDevice_Ctor(d3d9, raw_0x7b0, device9);
// Must: *self=device9; +4=d3d9+AddRef; zero caps/present banks; seed subsystems/globals
// Must NOT: assume caps already filled; treat ECX as self; invent product plate
// Keep NestedHash / PoolHost / per-slot ctors as separate units
// HostBase aux pool depends on DAT_00d1f624 from slot 0x1cf
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, size, sole CreateDevice wiring, zero-vs-fill split, and global pool seed. Product/slot English residual → **accept-with-gaps**.
