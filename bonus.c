int	display_handler(t_data *data)
{
	clock_t start_time, end_time;
	start_time = clock();

	ft_new_image(data, WIDTH, HEIGHT);
	draw_background(data);
	do_rays(data, data->dir, 1);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
		data->img->reference, 0, 10);
	
	mlx_destroy_image(data->mlx_ptr, data->img->reference);
	end_time = clock();
	double frame_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	data->total_time += frame_time;
	data->frame_count++;
	data->fps = data->frame_count / data->total_time;
	if (data->total_time > 0.5)
	{
		for (int x = 0; x < 20; x++)
			for (int y = 0; y < 10; y++)
				mlx_pixel_put(data->mlx_ptr, data->mlx_window, x, y, 0x000000);
		mlx_string_put(data->mlx_ptr, data->mlx_window, 1, 10, 0x00FF00, ft_itoa(data->fps));
		data->frame_count = 0;
		data->total_time = 0.0;
	}
	return (0);
}

	double		total_time;
	int			frame_count;
	int			fps;