# Review A (reconstruction fidelity): `aa_0044fee0` NestedHash0x10_StaticOnceGet_d1fcc0_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044fee0` |
| **VA** | `0x0044fee0`–`0x0044ff39` (**90 B**) |
| **Canonical name** | `NestedHash0x10_StaticOnceGet_d1fcc0_Inferred` |
| **Ghidra name** | `FUN_0044fee0` |
| **Review date** | `2026-07-29` (W35-E dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-E) |
| **Counterpart** | `reviews/B_aa_0044fee0_NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.md` |
| **System** | NestedHash static once-get |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 90 B) + `analyze_function_complete` + bulk xrefs |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

One-shot factory for static NestedHash bag **DAT_00d1fcc0**:

1. If once-flag bit 0 at **DAT_00d1fce8** clear → set bit, call **NestedHash_Ctor_Sentinel0x10** (`FUN_00457ac0`), `atexit(LAB_009c34b0)`.
2. Always return **`&DAT_00d1fcc0`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0044fee0_FUN_0044fee0.md` (+ W35-E append) |
| Annotated | `docs/reconstruction/raw/aa_0044fee0_FUN_0044fee0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044fee0.cpp` |
| Function | `docs/reconstruction/functions/aa_0044fee0_FUN_0044fee0.md` |
| Named | `docs/reconstruction/functions/aa_0044fee0_NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.md` |
| Live | decompile ≡ raw CF; full 90 B hex; 2 call sites |
| Context | W34-E NestedHash0x10 ctor; twin once-gets `00438c40` / `00438ca0` |

---

## 3. Signature (sealed)

```c
void *NestedHash0x10_StaticOnceGet_d1fcc0_Inferred(void);
```

| Slot | Source | Conf |
|---|---|---|
| return | `MOV EAX,00d1fcc0` | **High** |
| formals | none | **High** |
| RET | plain `C3` after `ADD ESP,0xC` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if ((DAT_00d1fce8 & 1) == 0) {
  DAT_00d1fce8 |= 1
  FUN_00457ac0(&DAT_00d1fcc0)
  atexit(LAB_009c34b0)
}
return &DAT_00d1fcc0
```

| Stage | Match | Conf |
|---|---|---|
| once-flag bit0 | **Yes** | **High** |
| NestedHash0x10 ctor | **Yes** | **High** |
| atexit registration | **Yes** | **High** |
| return object address (not ctor EAX) | **Yes** | **High** |
| Product English | open | **Low** |

---

## 5. Gaps / open

1. Product/PDB plate for this specific static (reject anmTrackEvents scaffold).
2. Full atexit dtor body (unowned).
3. Runtime / bit-exact / differential.

**Verdict:** **accept** — ABI/CF/flag/ctor/return sealed; residual is product English only (does not block accept for once-get pattern).
