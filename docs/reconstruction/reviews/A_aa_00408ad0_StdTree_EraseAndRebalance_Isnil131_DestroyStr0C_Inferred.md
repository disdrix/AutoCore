# Review A (reconstruction fidelity): `aa_00408ad0` StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408ad0` |
| **VA** | `0x00408ad0`–`0x00408e1d` inclusive (**846 B** / `0x34E`) |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred` |
| **Ghidra name** | `FUN_00408ad0` |
| **Prior scaffold** | `StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred` |
| **Review date** | `2026-08-05` (WQ9L-A OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00408ad0_StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred.md` |
| **System** | MSVC `std::_Tree` erase + RB rebalance (isnil@+0x131, string@+0x0c) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Erase one red-black tree node for the large-node string family:

- **isnil @ +0x131**, **color @ +0x130**, **std::string @ +0x0c**
- nil-iterator throw (`"invalid map/set<T> iterator"`)
- capture successor via OWN peer `StdTree_IteratorIncrement_Isnil131` (`0x00404000`)
- unlink (incl. two-child successor-swap path)
- fix head leftmost/rightmost via min/max isnil131
- RB rebalance if erased black (L/R rotate isnil131 family)
- `~basic_string(node+0xc)` then `operator_delete`
- size--; `*outIt = succ`; **`RET 0x0C`**

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9L-A re-verify) | `docs/reconstruction/raw/aa_00408ad0_FUN_00408ad0.md` |
| Annotated | `docs/reconstruction/raw/aa_00408ad0_FUN_00408ad0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00408ad0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00408ad0_FUN_00408ad0.md` |
| Named record | `docs/reconstruction/functions/aa_00408ad0_StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` entry/epilogue; string @ `0x00a152f0` |
| Caller | `FUN_00407b70` @ `0x00407bd2` (sole external) |
| Succ peer | OWN dual `StdTree_IteratorIncrement_Isnil131` @ `0x00404000` |
| Family peers | free-subtree `00409920`, erase-range `00407b70` (DestroyStr0C) |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| stack0 | `MapShell*` | early/map fields `+4` head / `+8` size; caller `PUSH ESI` |
| stack1 | `Node** outIt` | epilogue `MOV [EAX],EDX`; caller `LEA/PUSH` out slot |
| stack2 | `Node* node` | entry `MOV EAX,[ESP+0x18]`; isnil check `+0x131` |
| cleanup | **`RET 0x0C`** | `C2 0C 00` @ `0x00408e1b` |

### Epilogue hex tail (sealed)

```
894108 8b542460 8b44245c 8b4c2448 8910 64890d00000000 83c454 c20c00
// size-- | *outIt=succ | restore FS:[0] | ADD ESP,0x54 | RET 0x0C
```

### Caller site (`FUN_00407b70` @ `0x00407bd2`)

```text
LEA EDX,[ESP+0x14] ; CALL 00404000   // advance first
PUSH EDI           ; node
LEA EAX,[ESP+0x14] ; PUSH EAX       // outIt
PUSH ESI           ; map
CALL 00408ad0      ; RET 0x0C cleanup
```

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + `RET 0x0C` | **Confirmed** | bytes past false noreturn |
| Single-node erase (not range) | **Confirmed** | range is caller `FUN_00407b70` loop |
| isnil@+0x131 / color@+0x130 | **Confirmed** | opcodes + recolor path |
| string destroy @ +0x0c | **Confirmed** | `LEA ECX,[EBP+0xC]; CALL [0x009c62f4]` |
| Throw plate | **Confirmed** | `"invalid map/set<T> iterator"` @ `0x00a152f0`; ThrowInfo `DAT_00acc34c` |
| size-- when size>0 | **Confirmed** | epilogue |
| Succ via iterator++ isnil131 | **Confirmed** | `LEA EDX,[ESP+0x70]; CALL FUN_00404000` |
| Min/max extremity fix | **Confirmed** | `00404160` / `004043c0` |
| L/R rotate isnil131 family | **Confirmed** | `00403cb0` / `00403d00` |
| Sole external caller | **Confirmed** | 1 UNCONDITIONAL_CALL xref |
| Product map English name | **Open** | `_Inferred` |
| Full two-child splice plate exactness | **Med** | decomp marks mid blocks unreachable; clean is simplified |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH frame (`LAB_009bd0df`) | **Yes** |
| isnil throw | **Yes** |
| successor prep `FUN_00404000` | **Yes** |
| unlink + extremity fix (min/max) | **Yes** |
| two-child successor-swap path (`0x00408be0`+) | **Yes in bytes**; decomp falsely "unreachable" |
| RB rebalance if black | **Yes** |
| `~string` + delete + size-- + *outIt + ret 0xC | **Yes** (bytes seal epilogue) |

### Decompile caveats (sealed)

1. "Removing unreachable block" for two-child path — **bytes are live**; ports must keep full MSVC erase.
2. "Subroutine does not return" on `operator_delete` — **false**; size-- / outIt / RET 0xC follow.
3. `param_3[0x4c]` in decompile = color at **+0x130** (dword index ×4).

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| invalid map/set iterator string | **Yes** |
| isnil@+0x131 / color@+0x130 | **Yes** |
| `~basic_string` @ node+0x0c | **Yes** |
| Sole caller erase-range isnil131 DestroyStr0C | **Yes** |
| Family alignment with free-subtree / erase-range | **Yes** |
| Product/PDB English host type | **No** → **`_Inferred`** |

**Decision:** promote **`StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred`**. Aligns with free-subtree / erase-range family naming (`DestroyStr0C`). Reject merge with isnil31 (no string dtor) or isnil2d StringKey helpers. Reject freelist / range-body misname.

---

## 7. Gaps

1. Product/PDB demangle for host map type / key English.
2. Dual of rotate/min/max peers `00403cb0` / `00403d00` / `00404160` / `004043c0` (residual).
3. Full two-child successor-swap plate fidelity vs simplified clean (decomp unreachable warnings).
4. Runtime / bit-exact / image diff.

---

## 8. Verdict

CF/ABI/layout/string-dtor/throw/size-- sealed; product English + full two-child plate residual → **accept-with-gaps**.
