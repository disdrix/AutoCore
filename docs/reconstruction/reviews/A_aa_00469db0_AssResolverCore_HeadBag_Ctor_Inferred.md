# Review A (reconstruction fidelity): `aa_00469db0` AssResolverCore_HeadBag_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469db0` |
| **VA** | `0x00469db0`–`0x00469e12` exclusive (**98 B**) |
| **Canonical name** | `AssResolverCore_HeadBag_Ctor_Inferred` |
| **Ghidra name** | `FUN_00469db0` |
| **Review date** | `2026-07-29` (W32-E dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-E) |
| **Counterpart** | `reviews/B_aa_00469db0_AssResolverCore_HeadBag_Ctor_Inferred.md` |
| **System** | assets / AssResolverCore |
| **Evidence pass** | Live Ghidra decompile + analyze_function_complete + full 98 B `read_memory` + xrefs |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Placement constructor for AssResolverCore **head bag**:

1. `head = FUN_00423d60()` → store @ `+0x08`; zero `+0x0c`.
2. `FUN_004646e0(self+0x10, 9, &head)` → pointer vector reserve/fill capacity **9**.
3. `*(u32*)(self+0x20)=1`; `*(u32*)(self+0x24)=1`.
4. Return `self`.

Sole caller: `AssResolverCore_Ctor_Inferred` (`FUN_00983940`). Twin CF of Resolver-A member ctor `FUN_00423cf0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00469db0_FUN_00469db0.md` (+ W32-E append, full hex) |
| Annotated | `docs/reconstruction/raw/aa_00469db0_FUN_00469db0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssResolverCore_HeadBag_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00469db0.cpp` |
| Function records | `functions/aa_00469db0_FUN_00469db0.md` + named |
| Live | decompile ≡ raw CF; 98 B hex; `C2 04 00`; sole xref from `0098395d` |

---

## 3. Signature (sealed)

```c
// stack(self*); RET 4; returns self in EAX
AssResolverCore_HeadBag* AssResolverCore_HeadBag_Ctor_Inferred(AssResolverCore_HeadBag* self /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| self | Stack → ESI (`8B 74 24 18`) | **High** |
| return | `MOV EAX,ESI` | **High** |
| cleanup | `ADD ESP,0x10; RET 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH install
head = FUN_00423d60()
self[+0x08]=head; self[+0x0c]=0
FUN_004646e0(self+0x10, 9, &head)
self[+0x20]=1; self[+0x24]=1
SEH uninstall; return self
```

| Stage | Match | Conf |
|---|---|---|
| sentinel + vector-9 | **Yes** | **High** |
| flags 1/1 | **Yes** | **High** |
| Twin of 00423cf0 | **Yes** (decompile) | **High** |
| Product English | structural only | **Inferred** |

---

## 5. Gaps / open

1. Product/PDB class English for head bag fields.
2. Nested `FUN_00423d60` / `FUN_004646e0` fill product (not owned).
3. Meaning of +0x20/+0x24 beyond "written as 1".
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
