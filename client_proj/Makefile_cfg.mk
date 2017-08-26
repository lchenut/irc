C_FILES=srcs/buffer/buffer_del.c srcs/buffer/buffer_dump.c srcs/buffer/buffer_flush_fd.c srcs/buffer/buffer_new.c srcs/buffer/buffer_pop_line.c srcs/buffer/buffer_read_from_fd.c srcs/client/client_del.c srcs/client/client_disconnect.c srcs/client/client_exec/client_exec.c srcs/client/client_exec/client_exec_connect.c srcs/client/client_exec/client_exec_invite.c srcs/client/client_exec/client_exec_join.c srcs/client/client_exec/client_exec_list.c srcs/client/client_exec/client_exec_mode.c srcs/client/client_exec/client_exec_names.c srcs/client/client_exec/client_exec_nick.c srcs/client/client_exec/client_exec_part.c srcs/client/client_exec/client_exec_pass.c srcs/client/client_exec/client_exec_privmsg.c srcs/client/client_exec/client_exec_privmsg_soft.c srcs/client/client_exec/client_exec_quit.c srcs/client/client_exec/client_exec_topic.c srcs/client/client_exec/client_exec_user.c srcs/client/client_get_execute_fn.c srcs/client/client_loop.c srcs/client/client_new.c srcs/client/client_print_chan.c srcs/client/client_read_from_socket.c srcs/client/client_read_from_stdin.c srcs/client/client_register.c srcs/client/client_reply_exec/client_reply_324.c srcs/client/client_reply_exec/client_reply_353.c srcs/client/client_reply_exec/client_reply_366.c srcs/client/client_reply_exec/client_reply_401.c srcs/client/client_reply_exec/client_reply_404.c srcs/client/client_reply_exec/client_reply_482.c srcs/client/client_reply_exec/client_reply_all_params_to_home.c srcs/client/client_reply_exec/client_reply_exec_default.c srcs/client/client_reply_exec/client_reply_get_users.c srcs/client/client_reply_exec/client_reply_join.c srcs/client/client_reply_exec/client_reply_nick.c srcs/client/client_reply_exec/client_reply_part.c srcs/client/client_reply_exec/client_reply_ping.c srcs/client/client_reply_exec/client_reply_pop_params.c srcs/client/client_reply_exec/client_reply_privmsg.c srcs/client/client_reply_exec/client_reply_quit.c srcs/client/client_reply_exec/client_reply_topic.c srcs/client/client_set_address.c srcs/client/client_set_nick.c srcs/client/client_set_password.c srcs/client/client_set_port.c srcs/client/client_singleton.c srcs/client/client_try_connect.c srcs/client/client_try_connect_ipv4.c srcs/client/client_try_connect_ipv6.c srcs/client/client_try_connect_log.c srcs/client/client_write_sock.c srcs/command/command_ctrl_mvmt.c srcs/command/command_del.c srcs/command/command_del_left.c srcs/command/command_del_right.c srcs/command/command_get_curspos.c srcs/command/command_get_line.c srcs/command/command_get_line_scaled.c srcs/command/command_history_down.c srcs/command/command_history_push.c srcs/command/command_history_up.c srcs/command/command_move_end.c srcs/command/command_move_home.c srcs/command/command_move_left.c srcs/command/command_move_right.c srcs/command/command_new.c srcs/command/command_place_letter.c srcs/command/command_push.c srcs/command/command_quit_current_channel.c srcs/command/command_shift_tabulation.c srcs/command/command_tabulation.c srcs/command/line/line_copy.c srcs/command/line/line_del.c srcs/command/line/line_new.c srcs/command/line/line_realloc.c srcs/command/line/line_reset_line.c srcs/data/data_command.c srcs/data/data_ctrl_mvmt.c srcs/main/main.c srcs/prog/prog_del.c srcs/prog/prog_dump.c srcs/prog/prog_new.c srcs/prog/prog_run.c srcs/prog/prog_usage.c srcs/reply/replies.c srcs/reply/reply_del.c srcs/reply/reply_dump.c srcs/reply/reply_new.c srcs/reply/reply_to_string.c srcs/reply/rpl_tokenizer_addone.c srcs/reply/rpl_tokenizer_apply_rule01.c srcs/reply/rpl_tokenizer_apply_rule02.c srcs/reply/rpl_tokenizer_apply_rule03.c srcs/reply/rpl_tokenizer_apply_rule04.c srcs/reply/rpl_tokenizer_apply_rule05.c srcs/reply/rpl_tokenizer_del.c srcs/reply/rpl_tokenizer_delimit.c srcs/reply/rpl_tokenizer_new.c srcs/reply/rpl_tokenizer_tokenize.c srcs/utils/utils_concat.c srcs/utils/utils_gai_strerror.c srcs/utils/utils_is_nick_valid.c srcs/utils/utils_ischstring.c srcs/utils/utils_isspecial.c srcs/visual/visual_channel_del.c srcs/visual/visual_channel_del_by_name.c srcs/visual/visual_channel_disconnect.c srcs/visual/visual_channel_new.c srcs/visual/visual_channel_rename.c srcs/visual/visual_chat_decr.c srcs/visual/visual_chat_incr.c srcs/visual/visual_clear_prompt.c srcs/visual/visual_del.c srcs/visual/visual_dump_date.c srcs/visual/visual_get_char.c srcs/visual/visual_get_visual_channel.c srcs/visual/visual_move_curspos.c srcs/visual/visual_new.c srcs/visual/visual_perror.c srcs/visual/visual_print_bold.c srcs/visual/visual_print_border.c srcs/visual/visual_print_channel.c srcs/visual/visual_print_green.c srcs/visual/visual_print_newline.c srcs/visual/visual_print_prompt.c srcs/visual/visual_print_red.c srcs/visual/visual_refresh_current.c
C_DIRS=srcs srcs/buffer srcs/client srcs/client/client_exec srcs/client/client_reply_exec srcs/command srcs/command/line srcs/data srcs/main srcs/prog srcs/reply srcs/utils srcs/visual
H_FILES=incs/buffer.h incs/client.h incs/client_reply_exec.h incs/command.h incs/data.h incs/line.h incs/prog.h incs/replies.h incs/utils.h incs/visual.h
