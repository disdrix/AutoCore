# Review A (reconstruction fidelity): `aa_0096b930` phySkeleton_unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096b930` |
| **VA** | `0x0096b930`–`0x0096ba79` exclusive (**329 B**) |
| **Canonical name** | `phySkeleton_unserialize` |
| **Ghidra name** | `FUN_0096b930` |
| **Prior scaffold** | `FUN_0096b930` / `Named_phySkeleton_0096b930` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual W38-K) |
| **Counterpart** | `reviews/B_aa_0096b930_phySkeleton_unserialize.md` |
| **System** | physics / phy asset I/O (`phySkeleton.cpp`) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + parent decompile + `list_strings`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Unserialize one **phySkeleton** from a **PSKE** chunk (`tag = 0x50534b45` / fourCC `PSKE`; on-disk LE `"EKSP"`), **version 1 only**.

1. Enter chunk scope on the **stoChunkReader**.
2. Validate tag + version; on failure log and return **`0xffffffff`**.
3. On success: read bone count (binary vs text via **`reader+0x4044`**), prepare bones (`FUN_0096b150`), loop `phyBone_unserialize`, stamp **`bone+0x144 = index`**, bump generation / flags.
4. Leave scope if flag set; return count-read status.

Nested from **gfxBody** unserialize (`FUN_00765740`) at **`body+0x98`** (two version arms).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0096b930` (2026-08-04) ≡ raw 2026-07-23 |
| Bytes | `read_memory` full **329 B**; tag imm `45 4B 53 50`; **`C2 08 00`** ×2 |
| Strings | `0x00aa1254` path; invalid TAG / version plates |
| Bone dual | `A_aa_0096e280_phyBone_unserialize` — sole parent is this VA |
| Parent | `decompile_function` `FUN_00765740` — calls this @ `0x00765ac5` / `0x00765ea5` |
| Raw / annotated / clean | `aa_0096b930_*`, named + scaffold cleans |
| Callers | `get_function_callers` → `FUN_00765740` only (2 xrefs) |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 3. Signature (sealed)

```c
// stack (self*, reader*); RET 0x08
uint32_t phySkeleton_unserialize(phySkeleton* self, stoChunkReader* reader);
```

| Formal | Source | Conf |
|---|---|---|
| self* | stack0 → skeleton object | **Confirmed** |
| reader* | stack1 → EnterChunkScope arg | **Confirmed** |
| return status | EAX; fail `0xffffffff` | **Confirmed** |
| RET 0x8 | `C2 08 00` | **Confirmed** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| SEH + EnterChunkScope | prolog / call | **Confirmed** |
| tag == `0x50534b45` else log line `0x3a` | imm + string | **Confirmed** |
| version == 1 else format+log line `0x53` | branch + string | **Confirmed** |
| binary/text int via `reader+0x4044` | decompile | **Confirmed** |
| `FUN_0096b150(self, count)` | call order | **Confirmed** |
| bone loop + `+0x144 = index` | decompile ≡ phyBone dual | **Confirmed** |
| `+0x1C += 1`; `+4 \|= 3` | decompile | **Confirmed** |
| leave scope if flag; dual RET 8 | bytes | **Confirmed** |

### Recovered CF

```
SEH / ExceptionList
stoChunkReader_EnterChunkScope(reader)
if (tag != 0x50534b45) → log Invalid TAG → fail_exit
if (ver != 1) → format Invalid version → log → fail_exit
count_status = (reader+0x4044==0) ? read_i32_bin(&count) : read_i32_text(&count)
FUN_0096b150(self, count)
for (it = bones_begin; it != bones_end; ++it, ++index):
  phyBone_unserialize()
  (*it)->field_0x144 = index
*(self+0x1C) += 1
*(self+4) |= 3
leave_if(scope_flag); return count_status

fail_exit:
leave_if(scope_flag); return 0xffffffff
```

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Tag PSKE / version 1 gate | **Confirmed** | imm + strings |
| Fail return `0xffffffff` | **Confirmed** | both error tails |
| Success returns int-read status | **Confirmed** | `return uVar2` |
| `reader+0x4044` binary/text | **Confirmed** | same pattern as phyBone |
| Bone index @ `+0x144` written here | **Confirmed** | phyBone dual agrees |
| Product name phySkeleton | **Confirmed** | path + log strings |
| Semantics of `+4` flags / `+0x1C` counter | **Open** | offsets sealed, English open |
| `FUN_0096b150` product role | **Open** | unowned residual |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps / open

1. Product English for `FUN_0096b150` and flag/counter fields.  
2. Exact phyBone** ownership / allocator (vector at +0x0C/+0x10).  
3. SEH catch plate beyond leave-scope.  
4. Runtime / bit-exact on retail PSKE assets.

---

## 7. Verdict

**accept-with-gaps** — tag/version/ABI/bone-loop/index stamp sealed by live decompile + full body hex + product strings; nested helpers and field English open.
