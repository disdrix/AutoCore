# Review A (reconstruction fidelity): `aa_0096eec0` Host34_NestedHash0xC_Singleton_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096eec0` |
| **VA** | `0x0096eec0`–`0x0096ef6a` (**170 B**) |
| **Canonical name** | `Host34_NestedHash0xC_Singleton_Ctor_Inferred` |
| **Ghidra name** | `FUN_0096eec0` |
| **Review date** | `2026-07-29` (W35-S dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-S) |
| **Counterpart** | `reviews/B_aa_0096eec0_Host34_NestedHash0xC_Singleton_Ctor_Inferred.md` |
| **System** | NestedHash0xC host + singleton + type-token once-init |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 170 B) + `analyze_function_complete` + caller `FUN_0075f7f0` decompile + callee context |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher. No parent ledger.

---

## 1. Purpose

Placement constructor for a **0x34-byte** host:

1. SEH `LAB_009b1316`.
2. Publish **`DAT_00d1f04c = self`**.
3. **`NestedHash_Ctor_Sentinel0xC_Inferred(self)`** at base (W34-F).
4. **`self+0x28 = 1`**, **`+0x2c = 0`**, **`+0x30 = 0`**.
5. Once-init static type-token object (`DAT_00d1f7e4` / `PTR_FUN_00a9ef54` + atexit `LAB_009c3370`).
6. Map-register handler **`LAB_0096ed30`** with arg **0** into tree at **`*DAT_00d1f050 + 0x58`**, key **`0x00d1f7e4`** (via `FUN_0043bd40`).
7. Return self; **`RET 4`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-S append) | `docs/reconstruction/raw/aa_0096eec0_FUN_0096eec0.md` |
| Annotated | `docs/reconstruction/raw/aa_0096eec0_FUN_0096eec0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host34_NestedHash0xC_Singleton_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096eec0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0096eec0_FUN_0096eec0.md` |
| Named record | `docs/reconstruction/functions/aa_0096eec0_Host34_NestedHash0xC_Singleton_Ctor_Inferred.md` |
| Live | decompile; full 170 B hex; xref `0075fa2f`; caller `FUN_0075f7f0` (`new(0x34)`); W34-F NestedHash seal |
| Context | `DAT_00d1f7e4` also type token in `FUN_0096ea60` → `NDResourceCache_LookupOrCreate` |

---

## 3. Signature (sealed)

```c
// stack(self*); RET 4; returns self in EAX
Host34_NestedHash0xC* Host34_NestedHash0xC_Singleton_Ctor_Inferred(Host34_NestedHash0xC* self /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| self | Stack → ESI after SEH/pushes (`MOV ESI,[ESP+0x20]`) | **High** |
| return | `MOV EAX,ESI` | **High** |
| cleanup | `ADD ESP,0x10; RET 4` | **High** |
| ECX-thiscall | **No** | **High** |

Decompiler `undefined FUN_0096eec0(void)` is incomplete — do not trust as full ABI.

---

## 4. Control flow (clean ≡ raw ≡ bytes for layout; map path bytes-led)

```
self = stack_arg
DAT_00d1f04c = self
NestedHash_Ctor_Sentinel0xC(self)     // FUN_0043fdf0
self[+0x28]=1; self[+0x2c]=0; self[+0x30]=0
if (!(guard&1)): guard|=1; static_vtbl=&PTR_FUN_00a9ef54; atexit(LAB_009c3370)
slot = MapFindInsert(*DAT_00d1f050 + 0x58, key=0x00d1f7e4)  // FUN_0043bd40
*slot = LAB_0096ed30; slot[1] = 0
return self
```

| Stage | Match | Conf |
|---|---|---|
| NestedHash @ +0 | decompile ≡ bytes ≡ W34-F | **High** |
| Trailing fields | decompile ≡ bytes | **High** |
| Singleton write | decompile ≡ bytes | **High** |
| Once-init + atexit | decompile ≡ bytes | **High** |
| Map tree/key | **bytes only** (decompile drops setup) | **High** |
| Size 0x34 | sole caller `operator_new(0x34)` | **High** |

---

## 5. Gaps

- Product/PDB English for host class and map value type.
- Unowned `FUN_0043bd40` full node contract (partial from its decompile).
- `LAB_0096ed30` body (code site; not a defined function).
- Runtime meaning of `+0x28/+0x2c/+0x30`.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ABI, 0x34 layout, NestedHash0xC base, singleton, once-init type-token, and map handler registration. Residual product English + unowned map/handler bodies → **accept-with-gaps**.
