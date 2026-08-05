# Review A (reconstruction fidelity): `aa_007a26c0` Palantir_ExtendedHost_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a26c0` |
| **VA** | `0x007a26c0`–`0x007a297D` exclusive (**701 B**) |
| **Canonical name** | `Palantir_ExtendedHost_Ctor_Inferred` (was `FUN_007a26c0`) |
| **Review date** | `2026-08-04` (W37-R) |
| **Reviewer role** | Reconstruction fidelity (derived Palantir host placement ctor) |
| **Counterpart** | `reviews/B_aa_007a26c0_Palantir_ExtendedHost_Ctor_Inferred.md` |
| **System** | Palantir / client host shell |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `get_xrefs_to` + `read_memory` (body + float DATs). Prefer decompile/read_memory (**no** `disassemble_bytes`). Context-only: base `FUN_007543b0` (W35-I), callers `FUN_00948bd0` / `FUN_0094a6a0`.

---

## 1. Purpose

**Construct the derived Palantir host object** after the shared base ctor:

1. SEH frame (`LAB_009b0088`).
2. `Palantir_BaseCtor(self)` — stack self, `RET 4` (W35-I).
3. Install derived vtbl `PTR_FUN_00a97170` at `*self`.
4. `FUN_00424bf0` with **EAX = self+0xD8**.
5. Stamp large field block: zeros, flags, blend floats (1.0 / 0.1 / 64 / 15 / 0.01), resolution **800×600**, feature bytes.
6. `self+0x2D4 = FUN_004933f0()`; clear neighbors.
7. **`DAT_00d17958 = self`** (host singleton; distinct from base `DAT_00d1f058`).
8. `operator_new(0xA8)` circular list head with white RGBA clusters; store at `+0x2DC`.
9. Zero `+0x13C..+0x158` block; restore SEH; **return self**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007a26c0_FUN_007a26c0.md` (+ W37-R append) |
| Annotated | `docs/reconstruction/raw/aa_007a26c0_FUN_007a26c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Palantir_ExtendedHost_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007a26c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007a26c0_FUN_007a26c0.md` |
| Named record | `docs/reconstruction/functions/aa_007a26c0_Palantir_ExtendedHost_Ctor_Inferred.md` |
| Live Ghidra | decompile ≡ raw CF; full body hex via `read_memory` |
| Base pair | W35-I `Palantir_BaseCtor` — sole callee of base from this VA |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`, writes to unowned VAs.

---

## 3. Signature

```c
// stack self*; RET 4; EAX = self  (matches base ctor family)
uint32_t* Palantir_ExtendedHost_Ctor_Inferred(uint32_t* self);
```

| Item | Evidence |
|---|---|
| Convention | `MOV ESI,[esp+0x18]`; epilogue `MOV EAX,ESI; …; RET 4` |
| Not thiscall | No ECX this; stack arg only |
| Callees | `FUN_007543b0`, `FUN_00424bf0`, `FUN_004933f0`, `operator_new` |
| Body range | Entry `007a26c0`, exclusive end `007a297D` (**701 B**; Ghidra end `007a297c` drops final `00` of `RET 4`) |
| Xrefs | **2** call sites / **2** caller functions |

---

## 4. Control flow (sealed)

```
SEH install
base = Palantir_BaseCtor(self)
*self = PTR_FUN_00a97170
FUN_00424bf0(EAX=self+0xD8)
stamp fields / floats / flags / 800×600
self[+0x2D4] = FUN_004933f0()
DAT_00d17958 = self
node = new(0xA8); init colors + circular links; self[+0x2DC] = node
zero profiler/aux dwords
return self
```

| Stage | Match raw ≡ decompile ≡ bytes |
|---|---|
| Base ctor first | **Yes** — rel call `FUN_007543b0` |
| Derived vtbl | **Yes** — `C7 06 70 71 A9 00` |
| Singleton publish | **Yes** — `89 35 58 79 D1 00` |
| 800×600 immediates | **Yes** — `B9 20 03 00 00` / `B8 58 02 00 00` |
| RET 4 | **Yes** — `C2 04 00` |

**Thread safety:** none claimed.

---

## 5. Machine bytes

Full 701 B hex recorded in raw W37-R append.

Key immediates: `DAT_00a0f718` 0.01f, `g_flOne` 1.0f, `g_flMultiKillCountBlend` 0.1f @ `0x00a0f730`, `DAT_00a11088` 64.0f, `DAT_00aaa7a4` 15.0f.

---

## 6. Gaps

- RTTI / product demangle for type of `PTR_FUN_00a97170`.
- Product names for `FUN_00424bf0` and `FUN_004933f0` results.
- Exact product type of `0xA8` list node.
- Runtime / bit-exact / differential.

## 7. Verdict

**accept-with-gaps** — host extended-ctor CF, ABI, singleton, and layout stamps sealed; product type English open.
