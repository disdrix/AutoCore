# Review A (reconstruction fidelity): `aa_005399f0` Map_EraseNode_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005399f0` |
| **VA** | `0x005399f0` |
| **Body** | `0x005399f0`–`0x00539ca6` exclusive (**694** B) |
| **Canonical name** | `Map_EraseNode_Val12` (inferred) |
| **Ghidra symbol** | `FUN_005399f0` |
| **Review date** | `2026-07-29` (W27-R OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005399f0_Map_EraseNode_Val12.md` |
| **System** | std map/set tree single-node erase (Val12) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Erase one Val12 RB node: invalid-iterator throw, unlink + head fixup, black fixup with Val12 rotates, free node, **size--**, write successor to `*outIt`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005399f0_FUN_005399f0.md` (+ W27-R append) |
| Annotated | `docs/reconstruction/raw/aa_005399f0_FUN_005399f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_EraseNode_Val12.cpp` |
| Scaffold | `reconstructed-exact/FUN_005399f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005399f0_Map_EraseNode_Val12.md` |
| Live decompile | ≡ raw surface through `operator_delete` |
| Live body bytes | entry + true epilogue (`ret 8`) |
| Peer | `aa_0051cb40` Map_EraseNode (isnil@+0x29) |
| Rotates | `aa_00573170` / `aa_00418c10` Val12 |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | SEH `LAB_009a3ea2`; isnil check `+0x19` |
| True end | exclusive `0x00539ca6`; pad `CC`; next `FUN_00539cb0` |
| Epilogue | `83 c4 54 c2 08 00` — **ret 8** |
| Post-delete | size test / `--` / `*outIt` store after `operator_delete` |
| Throw string | `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| ThrowInfo | `DAT_00acc34c` |
| Color / isnil | +0x18 / +0x19 |

Entry hex (32 B):

```
64a1000000006aff68a23e9a00508b4424146489250000000083ec4880781900
```

Epilogue tail:

```
83c454c20800  ; add esp,0x54; ret 8
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw surface | **pass** |
| True body end vs Ghidra end | **pass** (bytes correct; Ghidra stale) |
| `ret 8` / 2 stack args | **pass** |
| thiscall ECX=map | **pass** |
| isnil@+0x19 throw | **pass** |
| Val12 rotates called | **pass** |
| size-- after delete | **pass** (bytes) |
| Clean avoids bare `undefined4` | **pass** |
| Full RB formal proof | **gap** |
| Product demangle | **gap** |
| `FUN_005ae0b0` product role | **gap** (out of ownership) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | ret 8 sealed |
| Val12 layout | **High** | matches buynode/rotates family |
| Sole caller range-erase | **High** | 1 xref |
| Name `Map_EraseNode_Val12` | **Inferred** | structural |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product / MSVC demangle for map type.  
2. Exact `FUN_005ae0b0` body (not owned).  
3. Line-by-line RB case matrix vs MSVC STL reference.  
4. Bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
