# Review A (reconstruction fidelity): `aa_004309c0` StdMap_StringKey_InsertOrFind

| Field | Value |
|---|---|
| **Stable ID** | `aa_004309c0` |
| **VA** | `0x004309c0`–`0x00430a96` |
| **Canonical name** | `StdMap_StringKey_InsertOrFind` |
| **Ghidra name** | `FUN_004309c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W21-P) |
| **Counterpart** | `reviews/B_aa_004309c0_StdMap_StringKey_InsertOrFind.md` |
| **System** | stl-map |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; callers `FUN_004303c0`, `FUN_00786470` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC `std::map<std::string,T>`-style **insert-or-find**:

1. Walk root by `operator<(key, node.key)` with isnil `@+0x2D`.
2. On miss: `FUN_00430b60` insert+rebalance → `{it, inserted=1}`.
3. On equal: `{existing, inserted=0}` — **no** mapped-value rewrite.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004309c0_FUN_004309c0.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_004309c0_FUN_004309c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_StringKey_InsertOrFind.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004309c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004309c0_FUN_004309c0.md` |
| Insert helper | `FUN_00430b60` `0x00430b60` (`"map/set<T> too long"`) |
| Predecessor | `FUN_004313d0` `0x004313d0` |
| Live | decompile ≡ raw; `read_memory` 215 B body; 3× `C2 04 00` |

---

## 3. Signature (sealed)

```c
// stack[0] = map*; EAX = basic_string* key; EBX = InsertPair* out
// return EAX = out; RET 4
InsertPair* StdMap_StringKey_InsertOrFind(void* map, const void* key, InsertPair* out);
```

| Formal | Source | Conf |
|---|---|---|
| map | stack0 (`mov edx,[esp+0xC]` after `sub esp,8`) | **High** |
| key | **EAX → EDI** | **High** |
| out | **EBX** (`mov [ebx],…` / `mov byte [ebx+4],0/1`) | **High** |
| return | EAX = EBX | **High** |
| cleanup | `RET 4` ×3 | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
goLeft=true; parent=header; cur=root
while !isnil(cur):
  goLeft = key < cur.key (+0xC)
  parent=cur; cur = goLeft ? left : right
if goLeft:
  if parent == header->_Left: insert(addleft=1) → out{it,1}; ret
  predecessor(&parent)
if parent.key < key: insert(goLeft) → out{it,1}; ret
else: out{parent,0}; ret
```

| Stage | Match | Conf |
|---|---|---|
| String key walk / isnil +0x2D | **Yes** | **High** |
| Leftmost insert flag 1 | **Yes** | **High** |
| Predecessor then parent&lt;key | **Yes** | **High** |
| Equal → inserted=0 no value write | **Yes** | **High** |
| Callees insert / pred / IAT `operator<` | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (215 B):
```
83ec088b54240c558b6a04568b7504807e2d00578bf8b00188442410752b8bff8d460c50578beeff15e8629c0083c40884c08844241074048b36eb038b7608807e2d0074db8b54241884c08bf58974240c74388b4a043b297524576a018d442420508bcd8bfae8350100008b085f5e890bc64304018bc35d83c408c204008d54240ce8890900008b74240c8d560c5752ff15e8629c0083c40884c074298b442410578b7c241c508d4c2420518bcde8ed0000008b105f5e8913c64304018bc35d83c408c204005f89335ec64304008bc35d83c408c20400
```

Callee targets: IAT `[0x009c62e8]`, `FUN_00430b60` `0x00430b60`, `FUN_004313d0` `0x004313d0`.

---

## 6. Gaps

- Product English for caller map owners.
- Full mapped-value typedef after string (`+0x28` consumer-side).
- Runtime / bit-exact.

## Verdict rationale

CF, ABI, and insert-or-find semantics sealed High from bytes + helpers. Residual is product naming / value layout at consumers → **accept-with-gaps**.
