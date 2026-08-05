# Review A (reconstruction fidelity): `aa_004ce940` CVOGLootGenerator_GetOrCreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce940` |
| **VA** | `0x004ce940` |
| **Canonical name** | `CVOGLootGenerator_GetOrCreate` (was `FUN_004ce940`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live re-decompile + bytes) |
| **Counterpart** | `reviews/B_aa_004ce940_CVOGLootGenerator_GetOrCreate.md` |
| **System** | loot / economy content (lazy singleton) |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** — **singleton ensure + size `0xbc` + EAX return sealed** |

---

## 1. Purpose

**Lazy singleton getter** for the global **`CVOGLootGenerator`** pointer at **`DAT_00b037e8`**.

On first use: allocate **`0xbc`** bytes, construct with **`FUN_0050c1b0(mem, DAT_00b041fc)`** (ctor dual: `LootManager_ctor_Inferred` / CVOGLootGenerator), store into the global, return pointer in **EAX**. If already non-null, return existing. OOM → store 0, return 0.

No stack arguments. Does not roll loot tables itself.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004ce940_FUN_004ce940.md` |
| Annotated | `docs/reconstruction/raw/aa_004ce940_FUN_004ce940.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGLootGenerator_GetOrCreate.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004ce940.cpp` |
| Function record | `docs/reconstruction/functions/aa_004ce940_FUN_004ce940.md` |
| Live re-decompile | Ghidra `decompile_function` @ `0x004ce940` — surface ≡ 2026-07-23 raw |
| Live bytes | Ghidra `read_memory` 128 B — dual `c3` epilogues + `CC` |
| Ctor | `FUN_0050c1b0` decompile + dual `LootManager_ctor_Inferred` |
| Peer init | `CVOGSectorMap_InitGenerators` (`DAT_00b037e8`, size `0xbc`, same ctor) |

**Not performed:** `disassemble_bytes`, Launcher, live CE, bit-exact image diff.

---

## 3. Control flow: live surface vs bytes

| Stage | Decompiler surface | Bytes |
|---|---|---|
| SEH frame | **Yes** (ExceptionList) | **Yes** (`6a ff` / `LAB_009a1f0c` / `fs:[0]`) |
| Load `DAT_00b037e8` | **Yes** | **Yes** `a1 e8 37 b0 00` |
| Short-circuit if non-null | **Yes** (as void return) | **Yes** `test eax; jnz` — **EAX preserved as return** |
| `operator_new(0xbc)` | **Yes** | **Yes** `68 bc 00 00 00` |
| Null → store 0 | **Yes** | **Yes** `xor eax,eax; mov DAT,eax` |
| Ctor `FUN_0050c1b0(DAT_00b041fc)` | **Yes** (thiscall collapse) | **Yes** `mov ecx,new; push DAT_00b041fc; call` |
| Store singleton | **Yes** | **Yes** `a3 e8 37 b0 00` |
| Return type | **void (wrong)** | **EAX = pointer** |

### Closed form (sealed)

```text
// no args; EAX = CVOGLootGenerator*
if (DAT_00b037e8 != 0) return DAT_00b037e8;
mem = operator_new(0xbc);
if (!mem) { DAT_00b037e8 = 0; return 0; }
DAT_00b037e8 = FUN_0050c1b0(mem, DAT_00b041fc);  // __thiscall
return DAT_00b037e8;
```

### Size **`0xbc`** + global **`DAT_00b037e8`** — **SEALED**

| Evidence | Detail |
|----------|--------|
| Bytes | `push 0xbc` before `operator_new` |
| Peer dual | InitGenerators plate: CVOGLootGenerator **0xbc** → `DAT_00b037e8` |
| Ctor dual | `LootManager_ctor_Inferred` same size / global |

---

## 4. Confidence

| Dimension | Level |
|---|---|
| Lazy ensure CF | **High / Sealed** |
| Size `0xbc` | **High / Sealed** |
| EAX return | **High / Sealed** |
| Ctor + table root | **High / Sealed** |
| Product class `CVOGLootGenerator` | **High** (peer plate; not string inside this body) |
| Thread-safe first create | **No lock** |
| Original PDB symbol | **Open** |

---

## 5. Gaps

1. Unlocked double-create race on concurrent first call.
2. Exact lifetime / free of `DAT_00b037e8` (who destroys).
3. Full type of `DAT_00b041fc` table root.
4. Runtime / bit-exact verification.

**Verdict:** Singleton ensure sealed. **accept-with-gaps.**
